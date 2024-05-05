# Sistema de registro de hóspedes para hotéis (Simulação)

<p align="center">
  <a href="https://github.com/lucascustodioCATOLICA/trabalho-estrutura-de-dados-coletivo/graphs/contributors">
    <img src="https://img.shields.io/github/contributors/lucascustodioCATOLICA/trabalho-estrutura-de-dados-coletivo.svg" alt="Contributors">
  </a>
  <a href="https://github.com/lucascustodioCATOLICA/trabalho-estrutura-de-dados-coletivo/commits/master">
    <img src="https://img.shields.io/github/commit-activity/m/lucascustodioCATOLICA/trabalho-estrutura-de-dados-coletivo.svg" alt="Commit Activity">
  </a>
  <a href="https://github.com/lucascustodioCATOLICA/trabalho-estrutura-de-dados-coletivo">
    <img src="https://img.shields.io/github/languages/code-size/lucascustodioCATOLICA/trabalho-estrutura-de-dados-coletivo" alt="Code Size">
  </a>
  <a href="https://github.com/lucascustodioCATOLICA/trabalho-estrutura-de-dados-coletivo">
    <img src="https://img.shields.io/tokei/lines/github/lucascustodioCATOLICA/trabalho-estrutura-de-dados-coletivo" alt="Lines of Code">
  </a>
</p>

 Este é um trabalho em grupo desenvolvido em linguagem C, o qual simula um sistema de registro de hóspedes para um hotel. Para a realização deste projeto foram utilizado conteúdos tanto abordados em sala de aula quanto adquiridos fora dela.

### Funcionalidades:

- Inserir hóspedes em quartos vazios.
- Listar hóspedes por ordem alfabética.
- Buscar hóspede.
- Editar hóspede.
- Liberar um quarto.
- Mostrar os números dos quartos vazios.
- Salvar lista de hóspedes com respectivos quartos em arquivo.

## Como usar

Para compilar o código, abra o terminal do compilador e siga as seguintes instruções:

Clone este repositório, em seguida entre dentro da pasta copiada

```bash
git clone https://github.com/lucascustodioCATOLICA/trabalho-estrutura-de-dados-coletivo.git
cd trabalho-estrutura-de-dados-coletivo/
```
<br>

> [!IMPORTANT]
> Antes de executar o código, copie o comando em 'Acentos:' para que possa ler corretamente os acentos da língua portuguesa

Compile o código `main.c` e execute
```
gcc main.c commands.c .\filesystem.c .\operations.c .\sort.c .\utils.c .\search.c -o output.exe
./output.exe
```
## Acentos:

No Powershell, execute o seguinte codigo para resolver problema dos acentos:

```
$OutputEncoding = [console]::InputEncoding = [console]::OutputEncoding =
New-Object System.Text.UTF8Encoding
```

Se for pelo Prompt de comando(CMD), execute o seguinte codigo para resolver problema dos acentos:

```
chcp 65001
```

 # Integrantes do projeto
 
| Foto | Nome | GitHub | Linkedin |
| ------ | ---- | ------ |--------- |
| <img src="https://media.licdn.com/dms/image/D4D03AQFPHwofyIH4Sw/profile-displayphoto-shrink_800_800/0/1701553141096?e=1720051200&v=beta&t=4opJbA9HxBOvEVeJxJhEnSmi5Sp2a9RDwcQrgSVbpJM" width="55" height="55"> | Pedro Carneiro de Lima | <a href="https://github.com/pedro-CL"><img src="https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white" target="_blanck"></a> | <a href="https://www.linkedin.com/in/pedro-carneiro-lima/"><img src="https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white" target="_blanck"></a> |
| <img src="https://media.licdn.com/dms/image/D4D03AQFgbE0r-V-aGg/profile-displayphoto-shrink_800_800/0/1707582136102?e=1720051200&v=beta&t=-j4-E4zCzr_baVQJzKnqQTvE2B7mnxGY4yUwpcdnQTg" width="55" height="55"> | Lucas Francisco Custódio | <a href="https://github.com/afslucass"><img src="https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white" target="_blanck"></a> | <a href="https://www.linkedin.com/in/afslucass/"><img src="https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white" target="_blanck"></a> |
| <img src="https://avatars.githubusercontent.com/u/133895618?v=4" width="55" height="55"> |  Arthur Faria dos Santos | <a href="https://github.com/Arthur-Faria-dos-Santos"><img src="https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white" target="_blanck"></a> | <a href="https://www.linkedin.com/in/arthur-faria-5a0378210/"><img src="https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white" target="_blanck"></a> |
| <img src="https://avatars.githubusercontent.com/u/142771408?v=4" width="55" height="55"> | Lyan Dias Soffa | <a href="https://github.com/grilo-16"><img src="https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white" target="_blanck"></a> | <a href="https://www.linkedin.com/in/lyan-dias-85717a270/"><img src="https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white" target="_blanck"></a> |
| <img src="" width="55" height="55"> | Pedro Luis da Silva | <a href="https://github.com/joseliaaquino1"><img src="https://img.shields.io/badge/github-%23121011.svg?style=for-the-badge&logo=github&logoColor=white" target="_blanck"></a> | <img src="https://img.shields.io/badge/linkedin-%230077B5.svg?style=for-the-badge&logo=linkedin&logoColor=white" target="_blanck"> |
