#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// 函数声明：用于窗口大小改变和处理输入的回调函数
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// 设置窗口的默认宽度和高度
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // 初始化GLFW库
    // ------------------------------
    glfwInit();  // 初始化GLFW库，设置OpenGL环境
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);  // 设置OpenGL的主版本号为3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  // 设置OpenGL的次版本号为3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 设置OpenGL的模式为核心模式（不支持固定函数管线）
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);  // 为macOS设置OpenGL的兼容性
#endif
    // 创建GLFW窗口
    // --------------------
    // 创建一个宽为800、高为600的窗口，并命名为"LearnOpenGL"
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "窗口创建失败" << std::endl;  // 如果窗口创建失败，则输出错误信息并退出
        glfwTerminate();  // 终止GLFW
        return -1;  // 返回错误码
    }
    
    // 设置当前窗口为OpenGL渲染的上下文
    glfwMakeContextCurrent(window);  // 使窗口成为当前OpenGL的渲染目标
    // 设置回调函数：当窗口大小发生变化时，调用framebuffer_size_callback函数
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // 初始化GLAD库
    // ---------------------------------------
    // 加载所有OpenGL函数指针
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))  
    {
        std::cout << "GLAD初始化失败" << std::endl;  // 如果初始化失败，输出错误信息并退出
        return -1;  // 返回错误码
    }

    // 渲染循环
    // ----------- 
    // 在窗口未关闭的情况下，持续执行渲染操作
    while (!glfwWindowShouldClose(window))  // 当窗口没有请求关闭时，持续执行循环
    {
        // 处理用户输入
        // ---------
        processInput(window);  // 检查用户输入，并响应相应的操作

        // ** 渲染管线的开始：设置清除颜色并清除缓冲区 **
        // 渲染操作
        // ---------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);  // 设置清除屏幕时的颜色为深绿色
        glClear(GL_COLOR_BUFFER_BIT);  // 清除颜色缓冲区（这里的颜色缓冲区指的是屏幕显示的内容）

        // ** 渲染管线的结束：交换缓冲区以显示当前帧的内容 **
        // 交换缓冲区并处理输入事件
        // --------------------------------
        glfwSwapBuffers(window);  // 交换前后缓冲区，将渲染的内容显示到窗口
        glfwPollEvents();  // 处理所有输入事件，如键盘按键、鼠标移动等
    }

    // 程序结束时，清理GLFW资源
    // ------------------
    glfwTerminate();  // 终止GLFW，释放其占用的资源
    return 0;  // 程序正常结束
}

// 处理输入：当按下ESC键时，关闭窗口
void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)  // 如果按下了ESC键
        glfwSetWindowShouldClose(window, true);  // 设置窗口关闭标志，退出程序
}

// 窗口大小变化时调用该回调函数，调整视口大小
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // 更新OpenGL视口，以适应新的窗口尺寸
    glViewport(0, 0, width, height);  // 设置视口为窗口的新宽高
}
