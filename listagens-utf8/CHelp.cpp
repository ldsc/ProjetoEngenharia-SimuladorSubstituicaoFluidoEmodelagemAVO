#include "CHelp.h"

using namespace std;

void CHelp::Ajuda()
	{
		cout << "\nSistema de Ajuda do Simulador de Substituição de Fluidos e Modelagem AVO" << "\n";
		cout << "Segue um abreviado manual sobre o uso do simulador proposto" << "\n";
		cout << "Simular ao capítulo 8 do Projeto de Engenharia" << "\n";
		
		cout << "SOBRE O SIMULADOR" << "\n\n";
		cout << "Desenvolvido por Maurício Matos e Rafael Boechat como projeto de engenharia para a disciplina de Programação Prática no segundo semestre de 2015" << "\n\n";
		
		cout << "SOBRE O TEMA" << "\n\n";
		cout << "Durante a etapa de exploração do petróleo utiliza-se uma série de métodos geofísicos como ferramenta para inferir sobre as características das rochas e fluidos em subsuperficie, buscando identificar possíveis intervalos de acumulação de hidrocarbonetos." << "\n";
		cout << "Diante disso, a importância da geofísica está relacionada com a possibilidade de caracterizar ao máximo um reservatório, fornecendo uma maior confiabilidade no potencial produtor de um sistema petrolífero. Tais métodos são utilizados em larga escala e para um conjunto de dados muito grande, o que destaca a relevância de se ter softwares que sejam capazes de trabalhar com esses dados." << "\n";
		cout << "Esta tendência é a motivação do nosso projeto de engenharia onde busca-se criar um simulador de substituição de fluidos e de modelagem AVO com a finalidade de caracterizar intervalos de reservatórios, visando auxiliar o usuario na etapa de interpretação geofísica." << "\n\n";

		cout << "PRÉ-REQUISITOS E DEPENDÊNCIAS" << "\n\n";
		cout << "- Ter o compilador g++ instalado" << "\n";
		cout << "- Ter o software Gnuplot instalado" << "\n";
		cout << "- Ter um arquivo com dados de perfilagem a disposição" << "\n\n";
		
		cout << "SOBRE O FUNCIONAMENTO" << "\n\n";
		cout << "Previamente, deve-se assegurar que os dados de perfis de entrada estejam na mesma pasta que o programa. Também é importante ressaltar que os dados de entrada sejam fisicamente coerentes, caso contrário resultados incoerentes serão obtidos." << "\n";
		cout << "No cabeçalho do programa, tem-se o nome, a universidade, a data, a versão e os autores do programa. Abaixo o usuário deve optar por realizar uma substituição de fluidos com modelagem AVO, substituição de fluidos a partir de dados de perfis ou obter ajuda. " << "\n\n";
		cout << "1.	Caso digite 1, a primeira opção será executada. " << "\n";
		cout << "a.	Primeiramente serão solicitados ao usuário dados de entrada dos fluidos, água e óleo e da rocha e seus componentes principais. " << "\n";
		cout << "b.	A matriz rochosa nesse trabalho foi modelada supondo ser composta por dois minerais, então serão solicitado propriedades elásticas referentes a esses dois minerais bem como a fração em volume de cada um na matriz da rocha." << "\n";
		cout << "c.	Caso a soma das frações dos dois minerais não seja igual a um, uma mensagem de erro será exibida já que seria fisicamente impossível nessa modelagem. Fica a cargo de o usuário prosseguir ou reiniciar a execução do programa." << "\n";
		cout << "d.	Após a entrada de dados o programa calculará as propriedades dos fluidos e rocha efetivos e utilizará as equações de Gassmann implementadas para realizar a substituição de fluidos. Com isso serão gerados três gráficos de propriedades do meio com o aumento da saturação de água. " << "\n";
		cout << "e.     As propriedades calculadas para a rocha e fluido efetivos são salvos nos arquivos externos Resultados_rocha.txt e Resultados_fluido.txt respectivamente. Ambos podem ser localizados na mesma pasta do programa." << "\n";
		cout << "f.	O próximo passo é fornecer ao programa os dados para a modelagem AVO. A partir do que já foi calculado, deve-se fornecer o valor de saturação em que se deseja realizar a modelagem. Além disso, é necessário fornecer as propriedades elásticas da camada superior ao reservatório." << "\n";
		cout << "g.	De posse de todos os dados, será realizada a modelagem AVO para os três métodos implementados e um gráfico de refletividade por ãngulo será gerado e a simulação encerrada." << endl << endl;
		cout << "2.	Caso digite 2, a segunda opção será executada. " << "\n";
		cout << "a.	Será solicitado ao usuário o nome do arquivo e formato com os dados de perfilagem. " << "\n";
		cout << "b.	Após o carregamento dos perfis, serão realizados os mesmos procedimentos apresentados nos itens a, b e c do caso anterior." << "\n";
		cout << "c.	Os perfis carregados são salvos na pasta do programa  juntamente com os dados calculados como descrito no item e do caso acima." << "\n";
		cout << "d.	Com isso, será realizada a substituição de fluidos de água para óleo no perfil carregado. Como dito, partimos do pressuposto que o perfil carregado é uma formação totalmente saturada com água e que passará a ser totalmente saturada com óleo. O comportamento da velocidade na camada com a mudança do fluido antes e depois pode ser visto no gráfico gerado, encerrando assim esta simulação." << "\n\n";
		
		cout << "\nVersão 1.0\a" << "\n";
		
	}
