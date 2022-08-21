#include <stdio.h>

int main() 
{ //Declaração das variáveis
  char cartao[17] = {'0'};
  int quantidadeDigitos = 0, somaTotal = 0, adicional = 0, auxiliar;
  //Input do cartão  
  printf("Número: ");
  scanf("%s", cartao);

  //Verificação da quantidade de dígitos 
  while(cartao[quantidadeDigitos] >= '0' && cartao[quantidadeDigitos] <= '9') 
  {
    quantidadeDigitos++;
  }
  
  //Primeira verificação se a quantidade de dígitos do cartão é válida
  if(quantidadeDigitos != 16 && quantidadeDigitos != 13) 
  {
    printf("INVALIDO\n");
    return 0;
  }
  //Seta o valor correto para o cálculo no caso de 13 dígitos
  if(quantidadeDigitos == 13) 
  {
    adicional++;
  }
  //Início do algorítimo de Luhn
  for(int i = 0; i < quantidadeDigitos; i++) 
  {
    cartao[i] -= '0';   
      if((i + adicional) % 2 == 0) 
      {
        auxiliar = cartao[i] * 2;
        auxiliar = (auxiliar % 10) + (auxiliar / 10);
        somaTotal += auxiliar;
      } 
      else 
      {
        somaTotal += cartao[i];
      }
  }
  //Verificação se o cartão é verdadeiro e qual é sua bandeira
  if(somaTotal % 10 != 0) 
  {
    printf("INVÁLIDO\n");
  } 
  else if(cartao[0] == 3) 
  {
    if(cartao[1] == 4 || cartao[1] == 7) 
    {
      printf("AMEX\n");
    } 
    else 
    {
      printf("INVÁLIDO\n");
    }
  } 
  else if(cartao[0] == 5) 
  {
    if(cartao[1] >= 1 && cartao [1] <= 5) 
    {
      printf("MASTERCARD\n");
    }
    else 
    {
      printf("INVÁLIDO\n");
    }
  } 
  else if(cartao[0] == 4) 
  {
    printf("VISA\n");
  } 
  else 
  {
    printf("INVÁLIDO\n");
  }

return 0;
}
