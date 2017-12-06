require 'wxruby'
require 'resource'

class TextValidatorCtrl < Wx::TextCtrl
  FILTER_NONE = 0
  FILTER_ALPHA = 1
  FILTER_NUMERIC = 2

  def initialize(parent, id, valor, pos, size, estilo, nfiltro)
    super(parent, id, valor, pos, size, estilo)
    
    evt_char {|event| on_char(event, nfiltro)}
  end

  def on_char(event,nfiltro)
    chave = event.key_code
    if nfiltro != FILTER_NONE then
      if (chave < Wx::K_SPACE || chave == Wx::K_DELETE || chave > 255) then
        event.skip
      elsif nfiltro == FILTER_ALPHA then
        if ((?a .. ?z).member?(chave) || (?A .. ?Z).member?(chave)) then
          event.skip
        end
      elsif nfiltro == FILTER_NUMERIC then
        if (?0 .. ?9).member?(chave)  then
          event.skip
        end
      else
        Wx::bell
      end
    else
      event.skip
    end
  end
end
