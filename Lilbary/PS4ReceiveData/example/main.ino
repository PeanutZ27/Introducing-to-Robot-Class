

void setup()
{
    Serial.begin(115200);
    Serial.println("Hello world");
    setRemote();
}

void loop()
{
    getRemote();
    Serial.print("LX:");
    Serial.print(controller_data.L_X);
    Serial.print(" LY:");
    Serial.print(controller_data.L_Y);
    Serial.print(" RX:");
    Serial.print(controller_data.R_X);
    Serial.print(" RY:");
    Serial.print(controller_data.R_Y);
    Serial.print(" L1:");
    Serial.print(controller_data.L1);
    Serial.print(" L2:");
    Serial.print(controller_data.L2);
    Serial.print(" L3:");
    Serial.print(controller_data.L3);
    Serial.print(" R1:");
    Serial.print(controller_data.R1);
    Serial.print(" R2:");
    Serial.print(controller_data.R2);
    Serial.print(" R3:");
    Serial.print(controller_data.R3);
    Serial.print(" Opt:");
    Serial.print(controller_data.Option);
    Serial.print(" Sha:");
    Serial.print(controller_data.Share);
    Serial.println();
}
