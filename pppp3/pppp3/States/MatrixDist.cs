namespace pppp3.Transports
{
    public class MatrixDist
    {
        public static List<List<int>> Value { get; private set; }

        private MatrixDist()
        {
            Value = new List<List<int>>()
            {
                new List<int> {0, 20, 30, 108, 110, 65, 398, 0, 0, 0, 0, 926, 0, 0, 0, 0},
                new List<int> {20, 0, 10, 98, 100, 55, 0, 415, 0, 483, 0, 0, 937, 0, 1204, 0},
                new List<int> {30, 10, 0, 108, 110, 65, 0, 0, 430, 0, 390, 0, 0, 652, 0, 1234},
                new List<int> {108, 98, 108, 0, 5, 0, 0, 0, 0, 581, 0, 0, 1035, 0, 1302, 0},
                new List<int> {110, 100, 110, 5, 0, 78, 0, 0, 540, 0, 500, 0, 0, 1062, 0, 1344},
                new List<int> {65, 55, 65, 0, 78, 0, 0, 0, 495, 0, 455, 0, 0, 1017, 0, 1299},
                new List<int> {398, 0, 0, 0, 0, 0, 0, 19, 23, 0, 26, 828, 0, 0, 0, 0},
                new List<int> {0, 415, 0, 0, 0, 0, 19, 0, 4, 32, 0, 0, 840, 0, 919, 0},
                new List<int> {0, 0, 430, 0, 540, 495, 23, 4, 0, 0, 40, 0, 0, 849, 0, 1010},
                new List<int> {0, 483, 0, 581, 0, 0, 0, 32, 0, 0, 4, 0, 872, 0, 951, 0},
                new List<int> {0, 0, 390, 0, 500, 455, 26, 0, 40, 4, 0, 0, 0, 889, 0, 1050},
                new List<int> {926, 0, 0, 0, 0, 0, 828, 0, 0, 0, 0, 0, 15, 16, 0, 285},
                new List<int> {0, 937, 0, 1035, 0, 0, 0, 840, 0, 872, 0, 15, 0, 2, 257, 281},
                new List<int> {0, 0, 952, 0, 1062, 1017, 0, 0, 849, 0, 889, 16, 2, 0, 0, 282},
                new List<int> {0, 1204, 0, 1302, 0, 0, 0, 919, 0, 951, 0, 0, 257, 0, 0, 2},
                new List<int> {0, 0, 1234, 0, 1344, 1299, 0, 0, 1010, 0, 1050, 285, 281, 282, 2, 0}
            };
        }
        private static MatrixDist _instance;
        public static MatrixDist Instance()
        {
            if (_instance == null)
                _instance = new MatrixDist();
            return _instance;
        }
    }
}
