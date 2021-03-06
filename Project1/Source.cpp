#include <stdio.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <time.h>
const char *PRONAME = "Project1";
const char *LOGNAME = "Project1.log";
struct tm *logtime;
void REFRESHLOGTIME()
{
    time_t timer;
    time(&timer);
    logtime = localtime(&timer);
}
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}
int main()
{
    freopen(LOGNAME, "w", stdout);
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow *window = glfwCreateWindow(800, 600, PRONAME, NULL, NULL);
    if (window == NULL)
    {
        REFRESHLOGTIME();
        printf("[%s](%d:%d:%d): Failed to create GLFW window\n", PRONAME, logtime->tm_hour, logtime->tm_min, logtime->tm_sec);
        glfwTerminate();
        return -1;
    }
    REFRESHLOGTIME();
    printf("[%s](%d:%d:%d): Create GLFW window success\n", PRONAME, logtime->tm_hour, logtime->tm_min, logtime->tm_sec);
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        // std::cout << "Failed to initialize GLAD" << std::endl;
        REFRESHLOGTIME();
        printf("[%s](%d:%d:%d): Failed to initialize GLAD\n", PRONAME, logtime->tm_hour, logtime->tm_min, logtime->tm_sec);
        return -1;
    }
    REFRESHLOGTIME();
    printf("[%s](%d:%d:%d): Initialize GLAD success\n", PRONAME, logtime->tm_hour, logtime->tm_min, logtime->tm_sec);
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    REFRESHLOGTIME();
    printf("[%s](%d:%d:%d): User close the window\n", PRONAME, logtime->tm_hour, logtime->tm_min, logtime->tm_sec);
    glfwTerminate();
    return 0;
}