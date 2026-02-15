#include "shader_tools.h"
#include <vector>

std::string shader_tools::loadShaderSource(const std::string& filepath) {

    std::ifstream file(filepath);
    if (!file.is_open()) {

        std::cout << std::filesystem::current_path() << std::endl;
        std::cerr << "Failed to open shader file: " << filepath << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();  
    return buffer.str();
}


GLuint shader_tools::compileShader(const std::string& path, GLenum type) {
    std::string src = shader_tools::loadShaderSource(path);
    if (src.empty()) return 0;

    GLuint shader = glCreateShader(type);
    const char* c_str = src.c_str();
    glShaderSource(shader, 1, &c_str, nullptr);
    glCompileShader(shader);

    GLint success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char log[512];
        glGetShaderInfoLog(shader, 512, nullptr, log);
        std::cerr << "Shader compilation error in " << path << ":\n" << log << std::endl;
    }

    return shader;
}

void shader_tools::logGPUChunk(GLuint textureID, int w, int h, int d) {
    int size = w * h * d;
    std::vector<uint8_t> buffer(size);

    // 1. Bind the texture you want to read
    glBindTexture(GL_TEXTURE_3D, textureID);

    // 2. Download the data from GPU to 'buffer'
    // Arguments: Target, Mip-level, Format, Type, Pointer
    glGetTexImage(GL_TEXTURE_3D, 0, GL_RED, GL_UNSIGNED_BYTE, buffer.data());

    // 3. Print the values
    std::cout << "--- GPU Texture Data Log ---" << std::endl;
    for (int i = 0; i < size; ++i) {
        // Log as integers so we don't see ASCII characters
        std::cout << static_cast<int>(buffer[i]) << " ";
        
        // Add a line break every 'width' for readability
        if ((i + 1) % w == 0) std::cout << "\n";
        // Add an extra break every slice
        if ((i + 1) % (w * h) == 0) std::cout << "--- End Slice ---\n";
    }
}
