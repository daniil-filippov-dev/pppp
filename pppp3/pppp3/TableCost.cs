namespace pppp3
{
    public struct TableCost
    {
        public int Price { get; private set; }
        public int Speed { get; private set; }
        public double Volume { get; private set; }

        public TableCost(int price, int speed, double volume)
        {
            Price = price;
            Speed = speed;
            Volume = volume;
        }
    }
}
