local ssid = "not"
local password = ""

wifi.setmode(wifi.STATION)
wifi.sta.config({ ssid = ssid, pwd = password })

local function show()
  print('Connected to ' .. ssid .. ' with IP ' .. (wifi.sta.getip()))
end

if wifi.sta.getip() then
  show()
else
  wifi.eventmon.register(wifi.eventmon.STA_GOT_IP, function()
    show()
  end)
end
