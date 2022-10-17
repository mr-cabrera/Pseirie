//esta es la clase que usamos para la libreria
class Motor_PAP{
    public: 
        Motor_PAP(int b1, int b2, int b3, int b4);  //objeto para acceder a la parte privada y poder declaras las bobinas
        void Mov_uno(bool Sentido); //funcion para el movimiento encendiendo una bobina a la vez
        void Mov_dos(bool Sentido); //funcion para el movimiento encendiendo dos bobinas a la vez
        void Mov_medio(bool Sentido);   //funcion para el movimiento de medio paso
        void Mov_uno_plus(bool Sentido, int pasos , int vel);
    private:
        int bob1; //variables de las bobinas
        int bob2;   
        int bob3;
        int bob4;
};
