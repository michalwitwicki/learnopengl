#include <gl.h>
#include "game.h"
#include "shaders.h"

#include "stb_image.h"

#define DEBUG
#include "cglm.h"


#include "buffer.h"
#include "bufferLayout.h"
#include "vertexArray.h"
#include "texture.h"


void gameInit(struct Game* game)
{
    windowInit(&game->window);
    rendererInit(&game->renderer);
}

void gameRun(struct Game* game)
{
    // #ifdef FALSE
    // float vertices[] =
    // {
    //     // positions          // colors           // texture coords
    //      0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
    //      0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    //     -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    //     -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
    // };
    float vertices[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };
    vec3 cubePositions[] = {
        { 0.0f,  0.0f,  0.0f },
        {2.0f,  5.0f, -15.0f},
        {-1.5f, -2.2f, -2.5f},
        {-3.8f, -2.0f, -12.3f},
        {2.4f, -0.4f, -3.5f},
        {-1.7f,  3.0f, -7.5f},
        {1.3f, -2.0f, -2.5f},
        {1.5f,  2.0f, -2.5f},
        {1.5f,  0.2f, -1.5f},
        {-1.3f,  1.0f, -1.5f}
    };
    unsigned int indices[] =
    {
        // note that we start from 0!
        0, 1, 3, // first Triangle
        1, 2, 3  // second Triangle
    };

    buffer_t vb;
    buffer_t eb;
    bufferLayout_t bl;
    vertexArray_t va;
    texture_t t;

    createVertexArray(&va);
    createBuffer(&vb, GL_ARRAY_BUFFER, vertices, sizeof(vertices));
    // createBuffer(&eb, GL_ELEMENT_ARRAY_BUFFER, indices, sizeof(indices));
    // createBufferLayout(&bl, GL_FLOAT, 3, 8 * sizeof(float), 0); // position
    // createBufferLayout(&bl, GL_FLOAT, 3, 8 * sizeof(float), 3 * sizeof(float)); // colors
    // createBufferLayout(&bl, GL_FLOAT, 2, 8 * sizeof(float), 6 * sizeof(float)); // texture coords
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);

    createTexture(&t, "data/container.jpg");

    shadersUseProgram(&game->renderer.shaders, SHADER_PROGRAM_BASIC);
    glUniform1i(glGetUniformLocation(*game->renderer.shaders.activeShaderProgram, "texture1"), 0);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, t.ID);


    // transformation stuff
    mat4 model;
    mat4 view;
    mat4 projection;
    glm_mat4_identity(model);
    glm_mat4_identity(view);
    glm_mat4_identity(projection);

    glm_rotate(model, glm_rad(-40.5f), (vec3) { 0.5f, 1.0f, 0.0f });
    glm_translate_z(view, -3.0f);
    glm_perspective(glm_rad(45.0f), 640 / 480, 0.1f, 100.0f, projection);
    unsigned int modelLoc = glGetUniformLocation(*game->renderer.shaders.activeShaderProgram, "model");
    unsigned int viewLoc = glGetUniformLocation(*game->renderer.shaders.activeShaderProgram, "view");
    unsigned int projectionLoc = glGetUniformLocation(*game->renderer.shaders.activeShaderProgram, "projection");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model[0]);
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view[0]);
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projection[0]);

    // enable z buffer
    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(game->window.glfwWindow))
    {
        // glm_rotate_x(model, glm_rad(-0.5f), model);
        // glm_rotate(model, glm_rad(-0.5f), (vec3) { 0.5f, 1.0f, 0.0f });
        // glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model[0]);


        // clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // glClear(GL_COLOR_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        bindVertexArray(&va);
        // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // glDrawArrays(GL_TRIANGLES, 0, 36);

        for (unsigned int i = 0; i < 10; i++)
        {
            mat4 new;
            glm_mat4_identity(new);
            glm_translate(new, cubePositions[i]);
            glm_rotate(new, glm_rad(-50.5f) * i * 20.0f, (vec3) { 0.5f, 1.0f, 0.0f });
            glUniformMatrix4fv(modelLoc, 1, GL_FALSE, new[0]);
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        // swap buffers and poll IO events
        glfwSwapBuffers(game->window.glfwWindow);
        glfwPollEvents();
    }

    deleteBuffer(&vb);
    // #endif

#ifdef FALSE
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

    // float vertices[] = {
    //     // positions      // colors
    //     0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // top right
    //     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom right
    //     -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom left
    //     -0.5f, 0.5f, 0.0f, 0.5f, 0.5f, 0.5f   // top left
    // };

    float vertices[] = {
        // positions          // colors           // texture coords
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
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
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // texture coord attribute
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);





    // load and create a texture 
    stbi_set_flip_vertically_on_load(1);
    unsigned int texture1;
    unsigned int texture2;

    glGenTextures(1, &texture1);
    glBindTexture(GL_TEXTURE_2D, texture1); // all upcoming GL_TEXTURE_2D operations now have effect on this texture object

    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    // set texture filtering parameters
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    unsigned char* data = stbi_load("data/container.jpg", &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load texture\n");
    }
    stbi_image_free(data);



    glGenTextures(1, &texture2);
    glBindTexture(GL_TEXTURE_2D, texture2);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load image, create texture and generate mipmaps
    // data = stbi_load(FileSystem::getPath("resources/textures/awesomeface.png").c_str(), &width, &height, &nrChannels, 0);
    data = stbi_load("data/awesomeface.png", &width, &height, &nrChannels, 0);
    if (data)
    {
        // note that the awesomeface.png has transparency and thus an alpha channel, so make sure to tell OpenGL the data type is of GL_RGBA
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load texture\n");
    }
    stbi_image_free(data);


    shadersUseProgram(&game->renderer.shaders, SHADER_PROGRAM_BASIC);
    glUniform1i(glGetUniformLocation(*game->renderer.shaders.activeShaderProgram, "texture1"), 0);
    glUniform1i(glGetUniformLocation(*game->renderer.shaders.activeShaderProgram, "texture2"), 1);


    // unbind VBO and VAO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    mat4 model;
    mat4 view;
    mat4 projection;
    glm_mat4_identity(model);
    glm_mat4_identity(view);
    glm_mat4_identity(projection);
    glm_rotate_x(model, glm_rad(-55.0f), model);
    glm_translate_z(view, -3.0f);
    glm_perspective(glm_rad(45.0f), 640 / 480, 0.1f, 100.0f, projection);
    unsigned int modelLoc = glGetUniformLocation(*game->renderer.shaders.activeShaderProgram, "model");
    unsigned int viewLoc = glGetUniformLocation(*game->renderer.shaders.activeShaderProgram, "view");
    unsigned int projectionLoc = glGetUniformLocation(*game->renderer.shaders.activeShaderProgram, "projection");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model[0]);
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view[0]);
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, projection[0]);


    glEnable(GL_CULL_FACE); // cull face
    // glCullFace(GL_BACK); // cull back face
    glFrontFace(GL_CW); // GL_CCW for counter clock-wise

    // //  bind Texture
    // glBindTexture(GL_TEXTURE_2D, texture1);
    // bind textures on corresponding texture units
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);

    // --- main loop ---
    // while (!glfwWindowShouldClose(game->window->glfwWindow))
    while (!glfwWindowShouldClose(game->window.glfwWindow))
    {
        // rotate the box
        // mat4 trans;
        // glm_mat4_identity(trans);
        // glm_rotate_z(trans, (float)glfwGetTime(), trans);
        // glm_translate_y(trans, 0.9);

        // unsigned int transformLoc = glGetUniformLocation(*game->renderer.shaders.activeShaderProgram, "transform");
        // glUniformMatrix4fv(transformLoc, 1, GL_FALSE, trans[0]);

        glm_rotate_x(model, (float)glfwGetTime() / 360, model);


        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model[0]);



        // clear the colorbuffer
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        // update the uniform color
        // float timeValue = glfwGetTime();
        // float greenValue = sin(timeValue) / 2.0f + 0.5f;
        // int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
        // glUniform4f(vertexColorLocation, 0.5f, greenValue, 1.0f, 1.0f);



        // be sure to activate the shader
        shadersUseProgram(&game->renderer.shaders, SHADER_PROGRAM_BASIC);

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
    glDeleteBuffers(1, &EBO);

    deleteShaderPrograms(&game->renderer.shaders);

    glfwDestroyWindow(game->window.glfwWindow);
    glfwTerminate();
#endif
}