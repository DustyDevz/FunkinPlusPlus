"""
Converts .hlsl -> .hpp by embedding the shader source as a raw string literal.
[ I'll improve this another time ]
"""

import sys
import re
from pathlib import Path

def clean_hlsl(source: str) -> str:
    """Light cleanup pass: normalize line endings, strip trailing
    whitespace per line, collapse 3+ blank lines down to 1, ensure
    a single trailing newline."""
    source = source.replace("\r\n", "\n").replace("\r", "\n")
    lines = [line.rstrip() for line in source.split("\n")]

    cleaned = []
    blank_streak = 0
    for line in lines:
        if line == "":
            blank_streak += 1
            if blank_streak > 1:
                continue
        else:
            blank_streak = 0
        cleaned.append(line)

    return "\n".join(cleaned).strip() + "\n"


def make_delimiter(source: str) -> str:
    """R"HLSL(...)HLSL" only breaks if the source itself contains
    the exact substring ')HLSL"'. Pick a delimiter guaranteed not
    to collide by checking first, falling back to a longer one."""
    for candidate in ["HLSL", "SHADER", "EMBEDDED_HLSL_SRC"]:
        if f")({candidate})\"" not in source and f"){candidate}\"" not in source:
            return candidate
    return "EMBEDDED_SHADER_SRC_UNIQUE"


def convert(input_path: Path, output_path: Path, var_name: str) -> None:
    source = input_path.read_text(encoding="utf-8")
    source = clean_hlsl(source)
    delimiter = make_delimiter(source)

    guard = output_path.stem.upper().replace(".", "_").replace("-", "_")

    header = (
        f"// Auto-generated from {input_path.name} — do not edit directly.\n"
        f"// Regenerate with: python tools/embed_shader.py {input_path} {output_path} {var_name}\n"
        f"#pragma once\n\n"
        f'static const char* {var_name} = R"{delimiter}(\n'
        f"{source}"
        f'){delimiter}";\n'
    )

    output_path.write_text(header, encoding="utf-8")
    print(f"Wrote {output_path} ({len(source)} bytes embedded as {var_name})")


def main():
    if len(sys.argv) != 4:
        print(__doc__)
        sys.exit(1)

    input_path = Path(sys.argv[1])
    output_path = Path(sys.argv[2])
    var_name = sys.argv[3]

    if not input_path.exists():
        print(f"Error: input file not found: {input_path}")
        sys.exit(1)

    convert(input_path, output_path, var_name)


if __name__ == "__main__":
    main()