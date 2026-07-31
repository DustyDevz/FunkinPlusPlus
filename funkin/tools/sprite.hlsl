struct VSInput {
    float2 Position : ATTRIB0;
    float2 UV       : ATTRIB1;
    float4 Color    : ATTRIB2;
};

struct PSInput {
    float4 Position : SV_POSITION;
    float2 UV       : TEXCOORD0;
    float4 Color    : COLOR0;
};

PSInput VSMain(VSInput input) {
    PSInput output;
    output.Position = float4(input.Position, 0.f, 1.f);
    output.UV = input.UV;
    output.Color = input.Color;
    return output;
}

Texture2D g_Texture;
SamplerState g_Texture_Sampler;

float4 PSMain(PSInput input) : SV_TARGET {
    return g_Texture.Sample(g_Texture_Sampler, input.UV) * input.Color;
}