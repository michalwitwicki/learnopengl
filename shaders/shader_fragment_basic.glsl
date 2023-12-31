// #version 330

// out vec4 FragColor;
// in vec3 ourColor;
// // "uniform vec4 ourColor;

// void main()
// {
//     FragColor = vec4(ourColor, 1.0f);
//     // FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
//     // FragColor = vertexColor;
//     // FragColor = ourColor;
// }

// ---------------------------------------------------------------------------------

// #version 330 core
// out vec4 FragColor;
  
// in vec3 ourColor;
// in vec2 TexCoord;

// uniform sampler2D texture1;
// uniform sampler2D texture2;

// void main()
// {
//     // FragColor = texture(ourTexture, TexCoord);
//     // FragColor = texture(ourTexture, TexCoord) * vec4(ourColor, 1.0);
//     FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
// }

// ---------------------------------------------------------------------------------

#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;

void main()
{
    // FragColor = texture(texture1, TexCoord) * vec4(ourColor, 1.0);
    FragColor = texture(texture1, TexCoord);
} 