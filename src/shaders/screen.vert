#version 460 core

out vec2 TexCoords; // Add this output

void main() {
    vec2 positions[3] = vec2[](
        vec2(-1.0, -1.0),
        vec2( 3.0, -1.0),
        vec2(-1.0,  3.0)
    );
    
    // Calculate UVs based on positions
    // This maps -1.0 to 0.0 and 1.0 to 1.0 (and 3.0 to 2.0)
    TexCoords = positions[gl_VertexID] * 0.5 + 0.5;

    gl_Position = vec4(positions[gl_VertexID], 0.0, 1.0);
}
