
-- Create callback.
cb = Callback.new()
cb.callback = function(values)
    print(values)
    return {"Z", "A"}
end

-- Run the callback.
run:callback(cb)

