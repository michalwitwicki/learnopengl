#version 330

out vec4 FragColor;
in vec3 ourColor;
// "uniform vec4 ourColor;

void main()
{
    FragColor = vec4(ourColor, 1.0f);
    // FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
    // FragColor = vertexColor;
    // FragColor = ourColor;
}