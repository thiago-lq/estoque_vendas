<?php
    // Variavel
    //$variavel = "Conteudo da variavel";
        //Tipos de variavel
            //b/oolean
                //$verdadeiro = TRUE;
               // $falso = FALSE;
            // String
               // $aspasDuplas = "palavra";
                //$aspasSimples = 'Palavra';
               // $templateString = <<<TXT
                   // O que você escreve aqui dentro é uma string
                   // ele começa com <<< depois tem uma palavra
                  //  e termina com essa mesma palavra
                 //   em comparação a gente deixa ela em maiuscula
               // TXT;
            // Numeral
                //$numero = 388;
                //$numeroReal = 388.388;
            // Lista e objeto
                //$semana = ['segunda', 'terça', 'quarta', 'quinta', 'sexta'];
                // $objeto->atributo;
                //$dia = $semana[0];
    //Operadores
        //Matematicos
           // $soma = 1 + 1;
           // $subtração = 1 - 1;
            //$multi = 2 * 5;
           // $div = 5 / 2;
            ///$resto = 5 % 2;
            //$potencia = 3 ** 3;
        //Logicos
            //$igualdade = 1 == 1;
            //$maiorQue = 2 > 1;
           // $menorQue = 1 < 2;
           // $diferente = 1 != 2;
            //$or = $verdadeiro ||$false;
            //$and = $verdadeiro && $false;
            //$not = !$verdadeiro;
    // condicionais
        // se nao
        //if ($condicao) {
            // faz a condicao
        //} else if ($condicao2) {
            //faz condicao 2
        //} else {
            // faz caso nao cai nos anteriores
        //}
        // escolha
        //switch ($variable) {
            //case 'value':
                # code...
                //break;
            //case 'value2':
                #code...
                //break;
            //default:
            #code...
            //break;
        //}
    // Loops
        //para
        //fot ($i=0; $i < 10; $i++){
            #code...
        //}
        //$semana = ['segunda', 'terca', 'quarta', 'quinta', 'sexta'];
        //foreach ($variable as $key => $value){
            //if($value == 'secta'){
                //echo "sextou";
            //}
        //}
        //enquanto
            //$a = 0;
            //while ($a <= 10){
                #code...
                //$a++;
            //}
    //funções

    //function soma($numero1, $Numero2) {
        //$soma = $numero1 + $numero2;
        //echo "A soma de $numero1 e $numero2 é $soma"
    //}
    //soma(2, 5);

    //function multiplicar($numero1, $numero2) {
        //$resultado = $numero1 * $numero2;
        //echo "A multiplicação de $numero1 e $numero2 é $resultado";
    //}
    //multiplicação(2, 5);

    function divisao($num1, $num2) {
        $div = $num1 / $num2;
        echo"A divisão de $num1 por $num2 é igual a $div";
    }
    divisao(10, 5);

    function par_impar($numQualquer){
        $p_i = $numQualquer;
        if($p_i % 2 == 0){
            echo "O numero é par";
        } else {
            echo "O numero é ímpar";
        }
    }
    par_impar(5);

?>