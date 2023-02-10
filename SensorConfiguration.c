#include<stdio.h>
//Initialize function that decimal to binary
long long converToBin(int n);

//Accelerometer Parameters
enum AccelRange{
    AR_2G=0,
    AR_4G,
    AR_8G,
    AR_16G
};
enum AccelBandwith{
    ABW_7_81Hz=0,
    ABW_15_63Hz,
    ABW_31_25Hz,
    ABW_62_5Hz,
    ABW_125Hz,
    ABW_250Hz,
    ABW_500Hz,
    ABW_1000Hz
};
enum AccelOperationMode{
    AO_Normal=0,
    AO_Suspend,
    AO_LowPower1,
    AO_Standby,
    AO_LowPower2,
    AO_DeepSuspend,
};
//Gyroskop Parameters
enum GyroRange{
    GR_2k_dps=0,
    GR_1k_dps,
    GR_500_dps,
    GR_250_dps,
    GR_125_dps
};
enum GyroBandwith{
    GBW_523Hz=0,
    GBW_230Hz,
    GBW_116Hz,
    GBW_47Hz,
    GBW_23Hz,
    GBW_12Hz,
    GBW_64Hz,
    GBW_32Hz
};
enum GyroOperationMode{
    GO_Normal=0,
    GO_FastPowerUp,
    GO_DeepSuspend,
    GO_Suspend,
    GO_AdvancedPowersave
};
//Magnometer Paremeters
enum MagDataOutput{
    MDO_2Hz=0,
    MDO_6Hz,
    MDO_8Hz,
    MDO_10Hz,
    MDO_15Hz,
    MDO_20Hz,
    MDO_25Hz,
    MDO_30Hz
};
enum MagOperationMode{
    MO_LowPower=0,
    MO_Regular,
    MO_EnhancedRegular,
    MO_HighAccuracy
};
enum MagPowerMode{
    MP_Normal=0,
    MP_Sleep,
    MP_Suspend,
    MP_ForceMode
};

int main(){
//Accelometer 
int accelRange=-1;
int accelBandwith=-1;
int accelOpMode=-1;

if(accelRange>=0 && accelBandwith>=0 && accelOpMode>=0){
    printf("ACC_Config Value(Decimal): %d\n",accelOpMode<<5|accelBandwith<<2|accelRange);
    printf("ACC_Config Value(Binary): %d\n",converToBin(accelOpMode<<5|accelBandwith<<2|accelRange));
    printf("ACC_Config Value(Hexadecimal): %X\n",accelOpMode<<5|accelBandwith<<2|accelRange);
}
//Gyroskop
int gyroRange=-1;
int gyroBandwith=-1;
int gyroOpMode=-1;

if(gyroRange>=0 && gyroOpMode>=0 && gyroBandwith>=0){
    printf("GYR_Config_0\n");
    printf("GYR_Config_0 Value(Decimal): %d\n",0<<6|gyroBandwith<<3|gyroRange);
    printf("GYR_Config_0 Value(Binary): %d\n",converToBin(0<<6|gyroBandwith<<3|gyroRange));
    printf("GYR_Config_0 Value(Hexadecimal): %X\n", 0<<6|gyroBandwith<<3|gyroRange);

    printf("\nGYR_Config_1\n");
    printf("GYR_Config_1 Value(Decimal):: %d\n",0<<3|gyroOpMode);
    printf("GYR_Config_1 Value(Binary):: %d\n",converToBin(0<<3|gyroOpMode));
    printf("GYR_Config_1 Value(Hexadecimal):: %X\n",0<<3|gyroOpMode);
}

//Magnometer
int magDataO=-1;
int magOpMode=-1;
int magPowerMode=-1;

if(magDataO>=0 && magOpMode>=0 && magPowerMode>=0){
    printf("Decimal: %d\n",magPowerMode<<5|magOpMode<<3|magDataO);
    printf("Binary: %d\n",converToBin(magPowerMode<<5|magOpMode<<3|magDataO));
    printf("Hexadecimal: %X",magPowerMode<<5|magOpMode<<3|magDataO);
}

}

long long converToBin(int n) {
  long long binary = 0;
  int remainder, i = 1;

  while (n!=0) {
    remainder = n % 2;
    n /= 2;
    binary += remainder * i;
    i *= 10;
  }
  return binary;
  }