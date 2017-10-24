#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[200];
    int estado;
    int id;
} xPelicula;


/**
 * Obtiene el primer indice libre del puntero.
 * @param puntero de la estructura pelicula
 * @param Longitud del array
 * @return el primer indice disponible
 */
int EspacioLibre(xPelicula* gente,int tam);
/**
 * Permite el ingreso de los datos de la pelicula
 * @param puntero a estructura de pelicula
 * @param Longitud del array
 * @return datos de la pelicula
 */
void generarDatos(xPelicula* pelicula,int tam);
/**
 * Permite el registro de una nueva Pelicula.
 * @param puntero a estructura de pelicula
 * @param Longitud del array
 * @return El registro de la pelicula cargado.
 */
void generarPelis(xPelicula* pelicula,int tam);

/**
 * Permite mostrar todos las peliculas cargadas hasta el momento
 * @param puntero a estructura de pelicula
 * @param Longitud del array
 * @return Todas las peliculas con sus respectvos datos cargados
 */
void mostrar(xPelicula* pelicula,int tam);
/**
 * Permite mostrar la Pelicula que fue ingresada
 * @param puntero a estructura de pelicula
 * @return Usuario ingresado
 */
void mostrarPeli(xPelicula* pelicula);
/**
 * Permite eliminar el registro de una pelicula
 * @param puntero a estructura de pelicula
 * @param Longitud del array
 * @return Si se produjo o no la eliminacion de la pelicula
 */
 void modificarPeli(xPelicula* pelicula,int tam);
/**
 * Permite Generar una pagina web con los datos cargados hasta el momento
 * @param puntero a estructura de pelicula
 * @param Longitud del array
 * @return Pagina HTML con las peliculas cargadas
 */
void borrarPeli(xPelicula* pelicula,int tam);
/**
 * Permite modificar el registro de un usuario
 * @param puntero a estructura de pelicula
 * @param Longitud del array
 * @return Si se produjo o no la modificacion  de la pelicula
 */
void GenerarPagina(xPelicula* pelicula,int tam);

 /** \brief Carga los archivos desde un archivo binario leido
  * \param puntero a estructura de pelicula
  * \param Longitud del array
  * \return 0 si Ok -1 por error
  *
  */
int cargarBinario(xPelicula* pelicula,int tam);

/**\brief Guarda los datos cargados en un archivo binario
 * \param puntero a estructura de pelicula
 * \param longitud del array
 * \return void
 *
 */
void guardarBinario(xPelicula* pelicula,int tam);












#endif // FUNCIONES_H_INCLUDED
