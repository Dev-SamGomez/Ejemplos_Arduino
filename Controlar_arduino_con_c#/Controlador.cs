System.IO.Ports.SerialPort Arduino; //Inicializamo la clasee SerialPort
Public Form1(){
    InitializeComponent();

    Arduino = new System.IO.Ports.SerialPort();
    //El puerto que coloquemos aqui, debera ser el mismo con el cual subimos el codigo a la tarjeta arduino
    Arduino.PortName = "COM3";
    Arduino.BaudRate = 9600;
    //Abrimos comunicacion con arduino por medio del puerto, y la informacion por medio del parametro Baudio.
    Arduino.Open();
}
Private void Form1_Load(object sender, EventArgs e){

}
Private void Form1_Closed(object sender, EventArgs e){
    //Si el puerto esta abierto al momento de cerrar la Forma, cerramos el puerto
    // de lo contrario seguira abierto y no se podra volver a conectar al arduino
    if (Arduino.IsOpen)
        Arduino.Close();
}
Private void BtnON_Click(object sender, EventArgs e){
    Arduino.Write("ON"); //Encendemos led del pin 10 que pusimos en arduino
}
Private void BtnOFF_Click(object sender, EventArgs e){
    Arduino.Write("OFF"); //Apagamos led del pin 10 que pusimos en arduino
}