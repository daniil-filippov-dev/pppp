namespace pppp3.States
{
    public class TableCosts
    {
        public static List<TableCost> Value { get; private set; }

        private TableCosts()
        {
            Value = new List<TableCost>()
            {
                new TableCost(500, 300, 100),
                new TableCost(200, 100, 500),
                new TableCost(100, 60, 50),
                new TableCost(0, 0, 0),
                new TableCost(200, 100, 500),
                new TableCost(100, 60, 50),
                new TableCost(0, 0, 0),
                new TableCost(0, 0, 0),
                new TableCost(100, 60, 50),
                new TableCost(500, 300, 100),
                new TableCost(200, 100, 500),
                new TableCost(100, 60, 50),
                new TableCost(0, 0, 0),
                new TableCost(200, 100, 500),
                new TableCost(100, 60, 50),
                new TableCost(500, 300, 100),
                new TableCost(200, 100, 500),
                new TableCost(100, 60, 50),
                new TableCost(0, 0, 0),
                new TableCost(200, 100, 500),
                new TableCost(100, 60, 50)
            };
        }

        private static TableCosts _instance;
        public static TableCosts Instance()
        {
            if (_instance == null)
                _instance = new TableCosts();
            return _instance;
        }
    }
}
