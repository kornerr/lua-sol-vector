
-- Print title, type, and values.
function printValues(title, values)
    print("----", title, "----")
    print(values)
    for k, v in pairs(values) do
        print("", k, "->", v)
    end
end

-- Create callback.
c = CallbackContainer.new()
c.callback = function(values)
    printValues("Inside callback", values)
    return {"Z", "A"}
end

-- Run the callback.
values = runner:call(c, {"A", "B"})
printValues("Running the callback", values)

