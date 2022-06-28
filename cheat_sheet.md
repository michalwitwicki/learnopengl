# GLWF functions 
glfwSetWindowShouldClose
glfwWindowShouldClose
glfwSetErrorCallback
glfwSetKeyCallback
glfwSetFramebufferSizeCallback
glfwWindowHint
glfwTerminate
glfwMakeContextCurrent
glfwSwapInterval
glfwSwapBuffers
glfwPollEvents
glfwDestroyWindow

# GLAD functions 
gladLoadGL


# OpenGL functions 
glViewport
glClearColor
glClear

### vertex buffer objects (VBO) stuff
glGenBuffers(1, &VBO)
glBindBuffer(GL_ARRAY_BUFFER, VBO)
glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW)

glCreateShader
glShaderSource
glCompileShader
glGetShaderiv
glGetShaderInfoLog

glCreateProgram
glAttachShader
glLinkProgram
glUseProgram
glDeleteShader

glVertexAttribPointer #ustawienie layoutu bufora
glEnableVertexAttribArray

### vertex array object (VAO) stuff
glGenVertexArrays(1, &VAO)
glBindVertexArray(VAO)

### Element Buffer Objects (EBO) stuff

### de allocate resources
glDeleteVertexArrays(1, &VAO)
glDeleteBuffers(1, &VBO)
glDeleteProgram(shaderProgram)