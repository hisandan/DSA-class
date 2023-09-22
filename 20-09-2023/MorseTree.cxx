#include "MorseTree.h"

#include <cstdlib>
#include <fstream>
#include <sstream>
# include <iostream>
#include <stack>

// -------------------------------------------------------------------------
MorseTree::Node::
Node( )
  : m_Value( '_' ),
    m_Left( NULL ),
    m_Right( NULL )
{
}

// -------------------------------------------------------------------------
MorseTree::Node::
~Node( )
{
  if( this->m_Left != NULL )
    delete this->m_Left;
  if( this->m_Right != NULL )
    delete this->m_Right;
}

// -------------------------------------------------------------------------
bool MorseTree::Node::
IsLeaf( ) const
{
  return( this->m_Left == NULL && this->m_Right == NULL );
}

// -------------------------------------------------------------------------
void MorseTree::Node::AddCharacter(const char& c, std::queue<char>& queue_code) {
  // TODO #1
  // Utilizamos los símbolos en la cola como ruta para recorrer el árbol
  // Al final de la ruta, agregamos el carácter al árbol

  // Si la cola está vacía, estamos al final de la ruta
  if (queue_code.empty()) {
    // Si el nodo es una hoja, podemos agregar el carácter
    if (this->IsLeaf())
      this->m_Value = c;
    // Si el nodo no es una hoja, no podemos agregar el carácter y mostramos un mensaje de error
    else
      std::cerr << "Error: Carácter \"" << c << "\" no agregado" << std::endl;
    return;
  }

  // Si la cola no está vacía, debemos continuar recorriendo el árbol
  // de acuerdo a los símbolos en la cola
  char symbol = queue_code.front();
  queue_code.pop();

  if (symbol == '.') {
    // Si el hijo izquierdo no existe, debemos crearlo
    if (this->m_Left == NULL)
      this->m_Left = new Node();
    // Continuamos recorriendo el árbol hacia la izquierda
    this->m_Left->AddCharacter(c, queue_code);
  } else if (symbol == '-') {
    // Si el hijo derecho no existe, debemos crearlo
    if (this->m_Right == NULL)
      this->m_Right = new Node();
    // Continuamos recorriendo el árbol hacia la derecha
    this->m_Right->AddCharacter(c, queue_code);
  } else {
    // Si el símbolo no es válido ('.' o '-'), mostramos un mensaje de error
    std::cerr << "Error: Carácter \"" << c << "\" no agregado" << std::endl;
  }

  return;
}


// -------------------------------------------------------------------------
char MorseTree::Node::Decode(std::queue<char>& code_queue) const {
  // TODO #2
  // Utilizamos los símbolos en la cola como ruta para recorrer el árbol
  // Al final de la ruta, retornamos el carácter encontrado

  // Si la cola está vacía, estamos al final de la ruta y retornamos el valor de este nodo
  if (code_queue.empty())
    return this->m_Value;

  // Si la cola no está vacía, debemos continuar recorriendo el árbol
  // de acuerdo a los símbolos en la cola
  char symbol = code_queue.front();
  code_queue.pop();

  if (symbol == '.') {
    // Si el hijo izquierdo no existe, no podemos continuar recorriendo el árbol
    if (this->m_Left == NULL)
      return '\0';
    
    // Continuamos recorriendo el árbol hacia la izquierda
    return this->m_Left->Decode(code_queue);
  } else if (symbol == '-') {
    // Si el hijo derecho no existe, no podemos continuar recorriendo el árbol
    if (this->m_Right == NULL)
      return '\0';
    
    // Continuamos recorriendo el árbol hacia la derecha
    return this->m_Right->Decode(code_queue);
  } else {
    // Si el símbolo no es válido ('.' o '-'), mostramos un mensaje de error y retornamos un carácter nulo ('\0')
    std::cerr << "Error: Carácter \"" << symbol << "\" no válido" << std::endl;
    return '\0';
  }
}


// -------------------------------------------------------------------------



std::string MorseTree::Node::Encode(char character) const {
  // ########## Revisar este punto ##########
  // TODO #3
  // Iniciar el resultado como una cadena vacía
  std::string result = "";
  
  // Crear una lista que contendrá información sobre los nodos padres de un nodo
  // El formato de cada elemento es ('.', id_del_padre) o ('-', id_del_padre)
  std::vector<std::pair<char, int>> list_parents;
  
  // Inicializar la lista con un elemento ficticio ('', -1) para el nodo raíz
  list_parents.push_back(std::make_pair(' ', -1));

  // Crear una pila de nodos que contendrá el recorrido actual; inicializarla con el nodo raíz
  std::vector<Node*> vector_nodes;
  vector_nodes.push_back(this->m_Left);
  vector_nodes.push_back(this->m_Right);

  // Agregar nodos ficticios para el nodo raíz ('.', id=0) y ('-', id=0)
  list_parents.push_back(std::make_pair('.', 0));
  list_parents.push_back(std::make_pair('-', 0));
  
  // Verificar si el nodo izquierdo o derecho contiene el caracter buscado
  if (this->m_Left->m_Value == character)
    return ".";
  if (this->m_Right->m_Value == character)
    return "-";

  // Posición en la lista de nodos actuales
  int index_current_node = 1;

  // Mientras la pila de nodos no esté vacía
  while (!vector_nodes.empty()) {
    // Obtener el nodo actual
    Node* current_node = vector_nodes[index_current_node - 1];

    // Verificar si existe un nodo izquierdo
    if (current_node->m_Left != NULL) {
      // Agregar información sobre el nodo izquierdo a la lista de padres
      list_parents.push_back(std::make_pair('.', index_current_node));
      // Agregar el nodo izquierdo a la pila de nodos
      vector_nodes.push_back(current_node->m_Left);
      
      // Verificar si el nodo izquierdo contiene el caracter buscado
      if (current_node->m_Left->m_Value == character) {
        result = ".";
        break;
      }
    }

    // Verificar si existe un nodo derecho
    if (current_node->m_Right != NULL) {
      // Agregar información sobre el nodo derecho a la lista de padres
      list_parents.push_back(std::make_pair('-', index_current_node));
      // Agregar el nodo derecho a la pila de nodos
      vector_nodes.push_back(current_node->m_Right);

      // Verificar si el nodo derecho contiene el caracter buscado
      if (current_node->m_Right->m_Value == character) {
        result = "-";
        break;
      }
    }

    // Avanzar al siguiente nodo en la pila de nodos
    index_current_node += 1;
  }

  // Reconstruir el resultado siguiendo la ruta desde el nodo hoja hasta el nodo raíz
  while (list_parents[index_current_node].second != -1) {
    result = list_parents[index_current_node].first + result;
    index_current_node = list_parents[index_current_node].second;
  }

  return result;
}

  



// -------------------------------------------------------------------------
MorseTree::
MorseTree( )
  : m_Root( NULL )
{
}

// -------------------------------------------------------------------------
MorseTree::
~MorseTree( )
{
  this->Clear( );
}

// -------------------------------------------------------------------------
bool MorseTree::
IsValid( ) const
{
  return( this->m_Root != NULL );
}

// -------------------------------------------------------------------------
char MorseTree::
Decode( const std::string& code ) const
{
  if( this->m_Root != NULL )
  {
    std::queue< char > code_queue;
    for(
      std::string::const_iterator cIt = code.begin( );
      cIt != code.end( );
      ++cIt
      )
      code_queue.push( *cIt );
    return( this->m_Root->Decode( code_queue ) );
  }
  else
    return( '\0' );
}

// -------------------------------------------------------------------------
std::string MorseTree::
Encode( char character ) const
{
  if( this->m_Root != NULL )
    return( this->m_Root->Encode( character ) );
  else
    return( "" );
}

// -------------------------------------------------------------------------
void MorseTree::
Clear( )
{
  if( this->m_Root != NULL )
    delete this->m_Root;
}

// -------------------------------------------------------------------------
bool MorseTree::
LoadFromFile( const std::string& filename )
{
  this->Clear( );
  std::ifstream input( filename.c_str( ) );
  if( !input )
    return( false );

  while( !input.eof( ) )
  {
    char character;
    std::string code;
    input >> character >> code;
    if( code != "" )
      this->AddCharacter( character, code );

  } // elihw

  input.close( );
  return( true );
}

// -------------------------------------------------------------------------
void MorseTree::
AddCharacter( const char& c, const std::string& code )
{
  if( this->m_Root == NULL )
    this->m_Root = new Node( );

  std::queue< char > code_queue;
  for(
    std::string::const_iterator cIt = code.begin( );
    cIt != code.end( );
    ++cIt
    )
    code_queue.push( *cIt );
  this->m_Root->AddCharacter( c, code_queue );
}

// eof - MorseTree.cxx
