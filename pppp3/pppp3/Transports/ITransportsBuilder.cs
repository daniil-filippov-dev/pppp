namespace pppp3.Transports
{
    public interface ITransportsBuilder
    {
        void AddCar(int i);
        void AddTrain(int i);
        void AddPlane(int i);
        void Reset();
    }
}
