
namespace Moviments{

class Moviment{

  public:
  // void set_moviment(float tx1,float ty1,float tz1,float rodar_eixo11,float rodar_eixo21,float rodar_eixo31);
  // Moviment();
  // float tx,ty,tz,rodar_eixo1,rodar_eixo2,rodar_eixo3;

  float tx,ty,tz;
  float leftLeg1,leftLeg2,leftLeg3;
  float rightLeg1,rightLeg2,rightLeg3;
  float leftArm1,leftArm2;
  float rightArm1,rightArm2;
    Moviment()
    {
        tx = ty = tz =0.0;
        leftLeg1=leftLeg2= leftLeg3 =0.0;
        rightLeg1=rightLeg2=rightLeg3=0.0;
        leftArm1=leftArm2=0.0;
        rightArm1=rightArm2=0.0;

    }

    void set_moviment(float _tx,float _ty,float _tz,
                      float _leftLeg1,float _leftLeg2,float _leftLeg3,
                      float _rightLeg1,float _rightLeg2,float _rightLeg3,
                      float _leftArm1,float _leftArm2,
                      float _rightArm1,float _rightArm2)
    {
        tx = _tx;
        ty = _ty;
        tz = _tz;
        leftLeg1 =_leftLeg1;
        leftLeg2 =_leftLeg2;
        leftLeg3 =_leftLeg3;
        rightLeg1 =_rightLeg1;
        rightLeg2 =_rightLeg2;
        rightLeg3 =_rightLeg3;
        leftArm1= _leftArm1;
        leftArm2= _leftArm2;
        rightArm1=_rightArm1;
        rightArm2=_rightArm2;
    }
};

}
