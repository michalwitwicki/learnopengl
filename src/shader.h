#ifndef _SHADER_H_
#define _SHADER_H_

enum ShaderType
{
    SHADER_BASIC = 0,
    SHADER_TYPE_COUNT
};

struct Shader
{
    unsigned int id;
};

struct ShaderProgram
{
    unsigned int id;
};

void initShaders();
void useShaderProgram(enum ShaderType shaderType);

#endif //_SHADER_H_

/*
1. Read file with shader
2. Compile it
3. Handle errors
4. Link into Shader Program
5. Handle errors
6. Use given shader program
*/