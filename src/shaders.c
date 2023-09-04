#include <gl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "shaders.h"
// #include "linmath.h"

#define DEFAULT_SHADER_PROGRAM SHADER_PROGRAM_BASIC

static char* readShaderSource(const char* sourcePath)
{
    FILE* file = fopen(sourcePath, "rb");

    if (file == NULL)
    {
        printf("Could not open file: %s\n", sourcePath);
        exit(EXIT_FAILURE);
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);  /* same as rewind(f); */

    char* buffer = malloc(fileSize + 1);
    fread(buffer, 1, fileSize, file);
    fclose(file);

    buffer[fileSize] = 0;

    return buffer;
}

static unsigned int compileShader(uint16_t shaderType, const char* shaderSourcePath)
{
    int success;
    char infoLog[512];
    const char* buffer = readShaderSource(shaderSourcePath);
    unsigned int shaderID = glCreateShader(shaderType);

    glShaderSource(shaderID, 1, &buffer, NULL);
    glCompileShader(shaderID);

    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
        printf("SHADER COMPILATION ERROR!!!\n");
        printf("In file: \n %s \n %s \n", shaderSourcePath, infoLog);
    }

    free((char*)buffer);

    return shaderID;
}

static void compileShaders(struct Shaders* shaders)
{
    // Declare paths to the shaders files
    char* vertexShadersSourcesPath[] =
    {
        "shaders/shader_vertex_basic.glsl"
    };

    char* fragmentShadersSourcesPath[] =
    {
        "shaders/shader_fragment_basic.glsl"
    };

    // Compile vertex shaders
    for (uint32_t i = 0; i < SHADER_VERTEX_COUNT; i++)
    {
        shaders->vertexShaders[i] = compileShader(GL_VERTEX_SHADER, vertexShadersSourcesPath[i]);
    }

    // Compile fragment shaders
    for (uint32_t i = 0; i < SHADER_FRAGMENT_COUNT; i++)
    {
        shaders->fragmentShaders[i] = compileShader(GL_FRAGMENT_SHADER, fragmentShadersSourcesPath[i]);
    }
}

static void linkShaderPrograms(struct Shaders* shaders)
{
    int success;
    char infoLog[512];

    shaders->shaderPrograms[SHADER_PROGRAM_BASIC] = glCreateProgram();
    glAttachShader(shaders->shaderPrograms[SHADER_PROGRAM_BASIC], shaders->vertexShaders[SHADER_VERTEX_BASIC]);
    glAttachShader(shaders->shaderPrograms[SHADER_PROGRAM_BASIC], shaders->fragmentShaders[SHADER_FRAGMENT_BASIC]);
    glLinkProgram(shaders->shaderPrograms[SHADER_PROGRAM_BASIC]);

    glGetProgramiv(shaders->shaderPrograms[SHADER_PROGRAM_BASIC], GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaders->shaderPrograms[SHADER_PROGRAM_BASIC], 512, NULL, infoLog);
        printf("SHADER PROGRAM LINKING ERROR!!!\n %s\n", infoLog);
    }

    glDeleteShader(shaders->vertexShaders[SHADER_VERTEX_BASIC]);
    glDeleteShader(shaders->fragmentShaders[SHADER_FRAGMENT_BASIC]);
}

void shadersUseProgram(struct Shaders* shaders, enum ShaderProgramType shaderProgramType)
{
    glUseProgram(shaders->shaderPrograms[shaderProgramType]);
    shaders->activeShaderProgram = &shaders->shaderPrograms[shaderProgramType];
}

void deleteShaderPrograms(struct Shaders* shaders)
{
    // Delete all programs
    for (uint32_t i = 0; i < SHADER_PROGRAM_COUNT; i++)
    {
        glDeleteProgram(shaders->shaderPrograms[i]);
    }
}

void shadersInit(struct Shaders* shaders)
{
    compileShaders(shaders);
    linkShaderPrograms(shaders);
    shadersUseProgram(shaders, DEFAULT_SHADER_PROGRAM);
}
