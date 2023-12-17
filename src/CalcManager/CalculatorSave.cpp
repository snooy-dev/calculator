//

#include "CalculatorSave.h"

CalculationManager::CalculatorSave::CalculatorSave(std::string path)
{
    m_stream = std::make_unique<std::wofstream>(path);
}

void CalculationManager::CalculatorSave::SaveHistory(const std::vector<std::shared_ptr<CalculationManager::HISTORYITEM>> history)
{
    for (std::shared_ptr<CalculationManager::HISTORYITEM> item : history)
    {
        CalculationManager::HISTORYITEMVECTOR& data = item->historyItemVector;

        WriteData(data.spTokens->size());
        for (const std::pair<std::wstring, int>& token : *(data.spTokens))
        {
            WriteData(token.first);
            WriteData(token.second);
        }
        WriteData(data.expression);
        WriteData(data.result);
    }
}

void CalculationManager::CalculatorSave::WriteData(const int data)
{
    *m_stream << data;
}

void CalculationManager::CalculatorSave::WriteData(const size_t data)
{
    *m_stream << data;
}

void CalculationManager::CalculatorSave::WriteData(const std::wstring data)
{
    *m_stream << data;
}
