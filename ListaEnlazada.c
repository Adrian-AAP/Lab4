#include <stdio.h>
#include <stdlib.h>


// Se define la estructura de los nodos
struct node {
	int val;
	struct node * next;	
};

// Se agrega un nodo con valor n a la posicion p
void addNode( struct node** head, int n, int p ){
	struct node *newNode;
	newNode = malloc(sizeof(struct node*));
	newNode->val = n;

	struct node *temp = *head;

	for( int i = 1; i < p-1; i++ ){
		if(temp->next != NULL){
			temp = temp->next;
		}
		else{
			printf("No se pudo agregar el nodo, el valor asignado a la posicion no es valido\n");
			return;
		}
	}
	newNode->next = temp->next;
	temp->next = newNode;
	return;
}

// Eliminar nodos con valor n
void elimNode( struct node** head, int n ){
	struct node *temp = *head;
	struct node *temp2;
	while(temp->val == n){
		temp2 = *head;
		*head = temp->next;
		temp = *head;
		free(temp2);
	}
	
	//Borra todos con el valor menos el primero
	while(temp->next != NULL){
		if(temp->next->val == n){	
			temp2 = temp->next;
			temp->next = temp->next->next;
			free(temp2);
		}
		temp = temp->next;
	}

}

// Agregar nodo con valor n al inicio
void addNodeStart( struct node** head, int n ){
	struct node *newNode;
	newNode = malloc(sizeof(struct node*));
	newNode->val = n; 
	newNode->next = *head;
	*head = newNode; //Se pone el nodo creado como primero
}

// Agrega nodo con valor n  al final
void addNodeEnd( struct node** head, int n){
	struct node *newNode;
	newNode = malloc(sizeof(struct node*));
	newNode->val =  n;
	newNode->next = NULL; //Ultimo nodo no tiene siguiente
	
	struct node *temp = *head;
	
	//Se busca el ultimo nodo actual
	while(temp->next != NULL){
		temp = temp->next;
	}
	
	//Se asigna el nuevo nodo a la ultima posicion
	temp->next = newNode; 
}

// Busca nodo por valor
void searchNode( struct node* head, int n ){
	struct node *temp = head;
	int pos = 1;
	int encontrado = 0; //1 si se encontro, 0 si no
	
	while(temp != NULL){
		if(temp->val == n){
		printf("se encontro el valor %d en la posicion %d\n", n, pos);
		encontrado = 1;
		}

		temp = temp->next;
	}
	
	if(encontrado == 0){
		printf("No se encontro el valor %d\n",n);
	}
}

//Imprime el nodo en la posicion p
void printNode( struct node ** head, int p ){
	struct node *temp = *head;

	for( int i = 1; i<p; i++){
		if(temp->next != NULL){
			temp = temp->next;
		}
		else{
			printf("No hay valor guardado en la posicion ingresada\n");
		}
	}

	printf("El valor en la posicion %d es %d\n", p, temp->val);

}

//Imprime toda la lista
void printList(struct node * head){
	struct node *temp = head;
	while(temp != NULL){
		printf(" %d ", temp->val);
		temp = temp->next;
	}
	printf("\n");
}

//Limpiar memoria
void nodeClear( struct node * node){
	if(node->next != NULL){
		nodeClear(node->next);
	}
	free(node);
}


int main(){
	// Crear nodo head sin valor asignado
	struct node *head = NULL;

	// Agegrar nodos
	addNodeStart(&head, 1); //Al inicio
	addNodeEnd(&head, 4); 	//Al final
	addNode(&head, 2, 2);	//Posicion arbitraria
	addNode(&head, 3, 3);	
	
	// Eliminar nodos por valor
	elimNode(&head, 1);

	//Buscar nodo por valor
	searchNode(head, 2);

	//Imprimir posicion
	printNode(&head, 1);

	//Imprimir lista
	printList(head);
	
	nodeClear(head);
}
