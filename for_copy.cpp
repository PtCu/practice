void DeCasteljau(std::vector<Ubpa::pointf2> &ret, Ubpa::pointf2 *p)
{
    const float step = 1.f / (Bezier_num - 1);
    for (float t = 0.f; t <= 1.f; t += step)
    {
        float x = std::pow((1 - t), 3) * p[0][0] + 3 * t * (1 - t) * (1 - t) * p[1][0] + 3 * t * t * (1 - t) * p[2][0] + t * t * t * p[3][0];
        float y = std::pow((1 - t), 3) * p[0][1] + 3 * t * (1 - t) * (1 - t) * p[1][1] + 3 * t * t * (1 - t) * p[2][1] + t * t * t * p[3][1];
        ret.push_back(Ubpa::pointf2(x, y));
    }
}
