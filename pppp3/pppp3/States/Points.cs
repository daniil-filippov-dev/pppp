namespace pppp3.States
{
    public class Points
    {
        public static List<string> Value { get; private set; }

        private Points()
        {
            Value = new List<string>()
            {
                "msk_AP", "msk_TS", "msk_WH", "mzh_TS",
                "mzh_WH", "zvn_WH", "NN_AP", "NN_TS",
                "NN_WH", "dzr_TS", "dzr_WH", "vlg_AP",
                "vlg_TS", "vlg_WH", "kam_TS", "kam_WH"
            };
        }
        private static Points _instance;
        public static Points Instance()
        {
            if (_instance == null)
                _instance = new Points();
            return _instance;
        }
    }
}
