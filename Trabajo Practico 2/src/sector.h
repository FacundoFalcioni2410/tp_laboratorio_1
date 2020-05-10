#ifndef SECTOR_H_
#define SECTOR_H_



typedef struct
{
    int id;
    char descripcion[20];

}eSector;


#endif /* SECTOR_H_ */



/**
 * @fn int int mostrarSectores(eSector sectores, tam)
 * @brief menu que recorre el vector sectores para mostrar los sectores con el objetivo de que el usuario sepa que id corresponde a que sector
 * @param sectores vector a recorrer con los sectores
 * @param tam tamaño del vector
 * @return devuelve la opcion ingresada por el usuario
 */
int mostrarSectores(eSector sectores[], int tam);

