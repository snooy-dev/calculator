//

#pragma once

#include <fstream>

#include "CalculatorHistory.h"

namespace CalculationManager
{
    class CalculatorSave
    {
    public:
        CalculatorSave(std::string path);

        void SaveHistory(const std::vector<std::shared_ptr<CalculationManager::HISTORYITEM>> history);

    private:
        std::unique_ptr<std::wofstream> m_stream;
                
        void WriteData(const int data);
        void WriteData(const size_t data);
        void WriteData(const std::wstring data);
    };
}
