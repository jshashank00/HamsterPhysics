/**
 * @file RotationSource.cpp
 * @author shash
 */
#include "pch.h"
#include "RotationSource.h"
#include "RotationSink.h"
RotationSource::RotationSource()
{

}
void RotationSource::AddSink(RotationSink *rotSink)
{
    mSinksVector.push_back(rotSink);
    rotSink->SetSource(this);


}
void RotationSource::Rotate(double rotation, double velocity)
{
    for (auto i: mSinksVector){
        i->Rotate(rotation, velocity);
    }
}
