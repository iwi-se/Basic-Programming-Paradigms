// EffectOfConst.cpp by Ulrich Eisenecker, April 20 2021

int main()
{
   const int ic1 { 1 }, ic2 { 2 };
   ic1 = 3; // Error, ic1 is const
   ic2 = 4; // Error, ic2 is const
}
