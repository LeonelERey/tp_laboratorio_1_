
typedef struct
{
    int posicion;
    char nombre[50];
    int seguidores;
    char apodo[50];
}EClub;

EClub* newClub();
//void generarBinario(ArrayList* lista, FILE* bin)
void agregarEquipo(ArrayList* lista,EClub* club);
void mostrarEquipo(ArrayList* lista,EClub* club);
int cargarBinario( EClub* movie,ArrayList* lista);
void guardarBinario(EClub* club,ArrayList* lista);
void EliminarEquipo(ArrayList* lista, EClub* club);
void ModifocarEquipo(ArrayList* lista, EClub* club);
void PosicionEspecificada(ArrayList* lista, EClub* club);
int comparaPersonas(void* club,void* Equipo);
int LeerEquipos( FILE* Archivo,ArrayList* lista);


