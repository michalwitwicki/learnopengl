#ifndef _SHADER_H_
#define _SHADER_H_

enum ShaderFragmentType
{
    SHADER_FRAGMENT_BASIC = 0,
    SHADER_FRAGMENT_COUNT
};

enum ShaderVertexType
{
    SHADER_VERTEX_BASIC = 0,
    SHADER_VERTEX_COUNT
};

enum ShaderProgramType
{
    SHADER_PROGRAM_BASIC = 0,
    SHADER_PROGRAM_COUNT
};

struct Shaders
{
    unsigned int fragmentShaders[SHADER_FRAGMENT_COUNT];
    unsigned int vertexShaders[SHADER_VERTEX_COUNT];
    unsigned int shaderPrograms[SHADER_FRAGMENT_COUNT];
    unsigned int shaderProgram;
};

void shadersInit();

#endif //_SHADER_H_

/*
1. Read file with shader
2. Compile it
3. Handle errors
4. Link into Shader Program
5. Handle errors
6. Use given shader program
*/