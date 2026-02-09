#version 430
out vec4 FragColor;
in vec2 TexCoords;

// Note: Use sampler2D here, NOT image2D
layout(binding = 0) uniform sampler2D screenTexture;

void main() {
    // This samples the red color we just wrote
    FragColor = texture(screenTexture, TexCoords);
}
