#define Byte char
#define Boolean bool
#define Short short int
#define Int int
#define Long long long int
#define Float  float
#define Double double

namespace SMCUtils
{
  namespace Java
  {
    namespace BuiltinTypes
    {
/*
      typedef bool          Boolean;
      typedef short int     Short;
      typedef int           Int;
      typedef long long int Long;
      typedef float         Float;
      typedef double        Double;
*/
    }
    namespace Util
    {
      namespace Random
      {
        class Random
        {
        private:
          Long m_seed;

          const static Long s_multiplier = 0x5DEECE66DL;
          const static Long s_addend = 0xBL;
          const static Long s_mask = (1L << 48) - 1;

          constexpr static Double S_DOUBLE_UNIT = 1.0 / (1L << 53);

          const static Long s_seedUniquifier = 8682522807148012L;
        private:
          constexpr static char* s_BadBound = "bound must be positive";
          constexpr static char* s_BadRange = "bound must be greater than origin";
          constexpr static char* s_BadSize  = "size must be non-negative";

        public:
          Random(){}
          Random(Long seed)
          {
            m_seed = Random::initialScramble(seed);
          }

        private:
          Long seedUniquifier()
          {
            while(true)
            {
              Long next = SMCUtils::Java::Util::Random::Random::s_seedUniquifier * 181783497276652981L;
              if (SMCUtils::Java::Util::Random::Random::s_seedUniquifier == next) //aka currunt = next
              {
                return next;
              }
            }
          }

          static Long initialScramble(Long seed)
          {
            return (seed ^ SMCUtils::Java::Util::Random::Random::s_multiplier) & SMCUtils::Java::Util::Random::Random::s_mask;
          }
        };
      }
    }
  }
}
