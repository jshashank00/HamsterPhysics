/**
 * @file RotationSink.cpp
 * @author shash
 */
#include "pch.h"
#include "RotationSink.h"
#include "RotationSource.h"

void RotationSink::Rotate(double rotation, double velocity)
{
    mRotation = rotation;
    mComponent->Rotate(mRotation, velocity);


}
RotationSink::RotationSink()
{

}

void RotationSink::SetSource(RotationSource * rotSource){
    mRotSource = rotSource;
}
void RotationSink::SetComponent(Component * component){
    mComponent = component;
}
