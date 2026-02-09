#include "shader_tools.h"

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
