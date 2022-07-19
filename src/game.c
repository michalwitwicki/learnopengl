#include <gl.h>
#include "game.h"

void gameInit(struct Game* game)
{
    windowInit(&game->window);
    rendererInit(&game->renderer);
}

void gameRun(struct Game* game)
{
    // --- triangle drawing stuff ---
    // float vertices[] = {
    //     -0.5f, -0.5f, 0.0f,
    //     0.5f, -0.5f, 0.0f,
    //     0.0f, 0.5f, 0.0f};
    // float vertices[] = {
    //     // positions         // colors
    //     0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // bottom right
    //     -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom left
    //     0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f    // top
    // };

    float vertices[] = {
        // positions      // colors
        0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // top right
        0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom left
        -0.5f, 0.5f, 0.0f, 0.5f, 0.5f, 0.5f   // top left
    };

    unsigned int indices[] = {
        // note that we start from 0!
        0, 1, 3, // first Triangle
        1, 2, 3  // second Triangle
    };

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // unbind VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // --- main loop ---
    // while (!glfwWindowShouldClose(game->window->glfwWindow))
    while (!glfwWindowShouldClose(game->window.glfwWindow))
    {
        // clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // be sure to activate the shader
        //glUseProgram(shaderProgram);
        // !!!
        // glUseProgram(game->renderer.shaderProgram);
        // !!!

        // update the uniform color
        // float timeValue = glfwGetTime();
        // float greenValue = sin(timeValue) / 2.0f + 0.5f;
        // int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
        // glUniform4f(vertexColorLocation, 0.5f, greenValue, 1.0f, 1.0f);

        // render the triangle
        glBindVertexArray(VAO);
        // glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // swap buffers and poll IO events
        glfwSwapBuffers(game->window.glfwWindow);
        glfwPollEvents();
    }

    // optional: de-allocate all resources once they've outlived their purpose:
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    // glDeleteBuffers(1, &EBO);


    // !!!
    // glDeleteProgram(game->renderer.shaderProgram);
    // !!!

    glfwDestroyWindow(game->window.glfwWindow);
    glfwTerminate();
}