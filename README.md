
  <h1 align="center">Minishell</h1>

  <h2>Description</h2>
  <p><strong>Minishell</strong> is a project from the 42 cursus that involves creating a simple Unix shell. The main objective is to understand the fundamentals of command-line interface programming, process creation and management, and signal handling. Minishell should be able to interpret and execute various shell commands, offering a basic yet functional shell environment.</p>
  <div align="center"><img height="400" src="https://github.com/PaLucena/MiniShell/blob/master/img/terminal.PNG"></div>

  <h2>Table of Contents</h2>
  <ul>
      <li><a href="#requirements">Requirements</a></li>
      <li><a href="#installation">Installation</a></li>
      <li><a href="#usage">Usage</a></li>
      <li><a href="#features">Features</a></li>
      <li><a href="#project-structure">Project Structure</a></li>
      <li><a href="#authors">Authors</a></li>
      <li><a href="#license">License</a></li>
  </ul>

  <h2 id="requirements">Requirements</h2>
  <p>To compile and run the project, you will need:</p>
  <ul>
      <li>A Unix operating system (Linux or macOS).</li>
      <li>gcc or any C compiler.</li>
      <li>Make.</li>
      <li>Readline library.</li>
  </ul>

  <h2 id="installation">Installation</h2>
  <p>Clone the project repository and navigate to the main directory:</p>
  <pre><code>git clone https://github.com/PaLucena/MiniShell.git
cd minishell</code></pre>
  <p>Compile the project using the included Makefile:</p>
  <pre><code>make</code></pre>
  <p>This will generate the <code>minishell</code> executable in the current directory.</p>

  <h2 id="usage">Usage</h2>
  <p>To start the minishell, run the following command:</p>
  <pre><code>./minishell</code></pre>
  <p>Once running, you can enter various shell commands as you would in a typical Unix shell.</p>

  <h2 id="features">Features</h2>
  <p>The Minishell project supports various features to provide a basic shell environment:</p>
  <ul>
      <li>Execute binary commands located in the system's PATH.</li>
      <li>Handle relative and absolute paths.</li>
      <li>Built-in commands: <code>cd</code>, <code>echo</code>, <code>env</code>, <code>setenv</code>, <code>unsetenv</code>, <code>exit</code>.</li>
      <li>Redirection of input and output (>, >>, <).</li>
      <li>Pipes (|) to connect commands.</li>
      <li>Signal handling for <code>Ctrl+C</code> and <code>Ctrl+D</code>.</li>
  </ul>

  <h2 id="project-structure">Project Structure</h2>
  <p>The project is organized into the following files and directories:</p>
  <ul>
      <li><code>src/</code>: Contains the source code of the shell.</li>
      <li><code>include/</code>: Contains the header files.</li>
      <li><code>Makefile</code>: Build script to generate the executable.</li>
      <li><code>README.md</code>: Project documentation.</li>
  </ul>

  <h2 id="authors">Authors</h2>
  <p>This project was developed by the 42 cursus students:</p>
  <ul>
      <li><a href="https://github.com/rdelicado" target="_blank">Rubén Delicado García Villaraco</a></li>
      <li><a href="https://github.com/PaLucena" target="_blank">Pablo Lucena González</a></li>
  </ul>

  <h2 id="license">License</h2>
  <p>This project is licensed under the MIT License. See the <code>LICENSE</code> file for more details.</p>
