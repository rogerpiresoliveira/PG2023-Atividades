///* Hello Triangle - c�digo adaptado de https://learnopengl.com/#!Getting-started/Hello-Triangle
// *
// * Adaptado por Rossana Baptista Queiroz
// * para a disciplina de Processamento Gr�fico - Unisinos
// * Vers�o inicial: 7/4/2017
// * �ltima atualiza��o em 27/02/2023
// *
// */
//
//#include <iostream>
//#include <string>
//#include <assert.h>
//#include <algorithm>
//#include <iostream>
//#include <corecrt_math_defines.h>
// // GLAD
//#include <glad/glad.h>
//// GLFW
//#include <GLFW/glfw3.h>
//
//using namespace std;
//
//// Prot�tipo da fun��o de callback de teclado
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
//
//// Prot�tipos das fun��es
//int setupShader();
//int setupGeometry();
//
//// Dimens�es da janela (pode ser alterado em tempo de execu��o)
//const GLuint WIDTH = 1000, HEIGHT = 1000;
//
//// C�digo fonte do Vertex Shader (em GLSL): ainda hardcoded
//const GLchar* vertexShaderSource = "#version 400\n"
//"layout (location = 0) in vec3 position;\n"
//"void main()\n"
//"{\n"
////...pode ter mais linhas de c�digo aqui!
//"gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
//"}\0";
//
////C�difo fonte do Fragment Shader (em GLSL): ainda hardcoded
//const GLchar* fragmentShaderSource = "#version 400\n"
//"uniform vec4 inputColor;\n"
//"out vec4 color;\n"
//"void main()\n"
//"{\n"
//"color = inputColor;\n"
//"}\n\0";
//
//// Fun��o MAIN
//int main()
//{
//	// Inicializa��o da GLFW
//	glfwInit();
//
//	//Muita aten��o aqui: alguns ambientes n�o aceitam essas configura��es
//	//Voc� deve adaptar para a vers�o do OpenGL suportada por sua placa
//	//Sugest�o: comente essas linhas de c�digo para desobrir a vers�o e
//	//depois atualize (por exemplo: 4.5 com 4 e 5)
//	/*glfwwindowhint(glfw_context_version_major, 4);
//	glfwwindowhint(glfw_context_version_minor, 6);
//	glfwwindowhint(glfw_opengl_profile, glfw_opengl_core_profile);*/
//
//	//Essencial para computadores da Apple
//#ifdef _apple_
//	glfwwindowhint(glfw_opengl_forward_compat, gl_true);
//#endif
//
//	// Cria��o da janela GLFW
//	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Ola Triangulo! - R�ger Pires de Oliveira", nullptr, nullptr);
//	glfwMakeContextCurrent(window);
//
//	// Fazendo o registro da fun��o de callback para a janela GLFW
//	glfwSetKeyCallback(window, key_callback);
//
//	// GLAD: carrega todos os ponteiros d fun��es da OpenGL
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//	}
//
//	// Obtendo as informa��es de vers�o
//	const GLubyte* renderer = glGetString(GL_RENDERER); /* get renderer string */
//	const GLubyte* version = glGetString(GL_VERSION); /* version as a string */
//	cout << "Renderer: " << renderer << endl;
//	cout << "OpenGL version supported " << version << endl;
//
//	// Definindo as dimens�es da viewport com as mesmas dimens�es da janela da aplica��o
//	int width, height;
//	glfwGetFramebufferSize(window, &width, &height);
//	glViewport(0, 0, width, height);
//
//	// Compilando e buildando o programa de shader
//	GLuint shaderID = setupShader();
//
//	// Gerando um buffer simples, com a geometria de um tri�ngulo
//	GLuint VAO = setupGeometry();
//
//	// Enviando a cor desejada (vec4) para o fragment shader
//	// Utilizamos a vari�veis do tipo uniform em GLSL para armazenar esse tipo de info
//	// que n�o est� nos buffers
//	GLint colorLoc = glGetUniformLocation(shaderID, "inputColor");
//	assert(colorLoc > -1);
//
//	glUseProgram(shaderID);
//
//	// Loop da aplica��o - "game loop"
//	while (!glfwWindowShouldClose(window))
//	{
//		// Checa se houveram eventos de input (key pressed, mouse moved etc.) e chama as fun��es de callback correspondentes
//		glfwPollEvents();
//
//		// Limpa o buffer de cor
//		glClearColor(0.00f, 0.00f, 0.00f, 1.0f); //cor de fundo
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		glLineWidth(10);
//		glPointSize(10);
//
//		glBindVertexArray(VAO); //Conectando ao buffer de geometria
//
//		// Chamada de desenho - drawcall
//		// Poligono Preenchido - GL_TRIANGLES
//		// CONTORNO - GL_LINE_LOOP
//		// PONTOS - GL_POINTS
//
//		glUniform4f(colorLoc, 0.5f, 0.4f, 0.3f, 1.0f);
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		glDrawArrays(GL_TRIANGLES, 3, 3);
//		glUniform4f(colorLoc, 0.5f, 0.7f, 0.8f, 1.0f);
//		glDrawArrays(GL_LINE_LOOP, 0, 3);
//		glDrawArrays(GL_LINE_LOOP, 3, 3);
//		glUniform4f(colorLoc, 0.1f, 0.4f, 0.3f, 1.0f);
//		glDrawArrays(GL_POINTS, 0, 6);
//
//
//		glBindVertexArray(0); //Desconectando o buffer de geometria
//
//		// Troca os buffers da tela
//		glfwSwapBuffers(window);
//	}
//	// Pede pra OpenGL desalocar os buffers
//	glDeleteVertexArrays(1, &VAO);
//	// Finaliza a execu��o da GLFW, limpando os recursos alocados por ela
//	glfwTerminate();
//	return 0;
//}
//
//// Esta fun��o est� bastante harcoded - objetivo � criar os buffers que armazenam a 
//// geometria de um tri�ngulo
//// Apenas atributo coordenada nos v�rtices
//// 1 VBO com as coordenadas, VAO com apenas 1 ponteiro para atributo
//// A fun��o retorna o identificador do VAO
//int setupGeometry()
//{
//	GLfloat vertices[] = {
//		-0.50f,  0.50f, 0.0f,
//		 0.50f,  0.50f, 0.0f,
//		 0.00f,  0.00f, 0.0f,
//		-0.50f, -0.50f, 0.0f,
//		 0.50f, -0.50f, 0.0f,
//	};
//
//	GLuint VBO, VAO;
//
//	//Gera��o do identificador do VBO
//	glGenBuffers(1, &VBO);
//	//Faz a conex�o (vincula) do buffer como um buffer de array
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	//Envia os dados do array de floats para o buffer da OpenGl
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	//Gera��o do identificador do VAO (Vertex Array Object)
//	glGenVertexArrays(1, &VAO);
//	// Vincula (bind) o VAO primeiro, e em seguida  conecta e seta o(s) buffer(s) de v�rtices
//	// e os ponteiros para os atributos 
//	glBindVertexArray(VAO);
//	//Para cada atributo do vertice, criamos um "AttribPointer" (ponteiro para o atributo), indicando: 
//	// Localiza��o no shader * (a localiza��o dos atributos devem ser correspondentes no layout especificado no vertex shader)
//	// Numero de valores que o atributo tem (por ex, 3 coordenadas xyz) 
//	// Tipo do dado
//	// Se est� normalizado (entre zero e um)
//	// Tamanho em bytes 
//	// Deslocamento a partir do byte zero 
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	// Observe que isso � permitido, a chamada para glVertexAttribPointer registrou o VBO como o objeto de buffer de v�rtice 
//	// atualmente vinculado - para que depois possamos desvincular com seguran�a
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//
//	// Desvincula o VAO (� uma boa pr�tica desvincular qualquer buffer ou array para evitar bugs medonhos)
//	glBindVertexArray(0);
//
//	return VAO;
//	delete[] vertices;
//}
//
//// Fun��o de callback de teclado - s� pode ter uma inst�ncia (deve ser est�tica se
//// estiver dentro de uma classe) - � chamada sempre que uma tecla for pressionada
//// ou solta via GLFW
//void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
//{
//	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, GL_TRUE);
//}
//
////Esta fun��o est� basntante hardcoded - objetivo � compilar e "buildar" um programa de
//// shader simples e �nico neste exemplo de c�digo
//// O c�digo fonte do vertex e fragment shader est� nos arrays vertexShaderSource e
//// fragmentShader source no ini�io deste arquivo
//// A fun��o retorna o identificador do programa de shader
//int setupShader()
//{
//	// Vertex shader
//	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//	// Checando erros de compila��o (exibi��o via log no terminal)
//	GLint success;
//	GLchar infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//	// Fragment shader
//	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShader);
//	// Checando erros de compila��o (exibi��o via log no terminal)
//	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//	// Linkando os shaders e criando o identificador do programa de shader
//	GLuint shaderProgram = glCreateProgram();
//	glAttachShader(shaderProgram, vertexShader);
//	glAttachShader(shaderProgram, fragmentShader);
//	glLinkProgram(shaderProgram);
//	// Checando por erros de linkagem
//	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShader);
//
//	return shaderProgram;
//}