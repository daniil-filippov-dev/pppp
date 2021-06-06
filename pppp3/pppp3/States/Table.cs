namespace pppp3.States
{
    class Table
    {
        public static Dictionary<string, int> Value { get; private set; }

        private Table()
        {
            Value = new Dictionary<string, int>()
            {
                {"msk", 0},
                {"mzh", 1},
                {"zvn", 2},
                {"NN", 3},
                {"dzr", 4},
                {"vlg", 5},
                {"kam", 6}
            };
        }
        private static Table _instance;
        public static Table Instance()
        {
            if (_instance == null)
                _instance = new Table();
            return _instance;
        }
    }
}
