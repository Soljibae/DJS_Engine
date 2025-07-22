#include <GLFW/glfw3.h>

int main()
{
    // GLFW 초기화
    if (!glfwInit())
    {
        return -1;
    }

    // 윈도우 생성
    GLFWwindow* window = glfwCreateWindow(800, 600, "Blank Project Test", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // 메인 루프
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}