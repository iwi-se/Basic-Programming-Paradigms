// PingPongImpossible.cpp by Ulrich Eisenecker, August 31, 2021
// Caution: This program does not compile!

class Ping
{
   public:
      void method(Pong& p,int n)
      {
         if (n > 0)
         {
            p.method(*this,n - 1);
         }
      }
};

class Pong
{
   public:
      void method(Ping& p,int n)
      {
         if (n > 0)
         {
            p.method(*this,n - 1);
         }
      }
};

int main()
{
   Ping ping;
   Pong pong;
   ping.method(pong,3);
}
