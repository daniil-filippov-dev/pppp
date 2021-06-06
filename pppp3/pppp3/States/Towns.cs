namespace pppp3.States
{
    public class Towns
    {
        public static Dictionary<string, int> Value { get; private set; }

        private Towns()
        {
            Value = new Dictionary<string, int>()
            {
                {"Moscow", 2},
                {"Mozhaisk", 4},
                {"Zvenigorod", 5},
                {"Nizhniy Novgorod", 8},
                {"Dzerzhinsk", 10},
                {"Volgograd", 13},
                {"Kamishin", 15}
            };
        }
        private static Towns _instance;
        public static Towns Instance()
        {
            if (_instance == null)
                _instance = new Towns();
            return _instance;
        }
    }
}
