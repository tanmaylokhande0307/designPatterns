const createHandler = (handleFunc) => {
  let nextHandler = null;

  const handler = {
    setNext(handler) {
      nextHandler = handler;
      return handler;
    },

    handleRequest(request) {
      handleFunc(request, (nextRequest) => {
        if (nextHandler) {
          nextHandler.handleRequest(nextRequest);
        } else {
          console.log("No handler available for this request.");
        }
      });
    },
  };

  return handler;
};

const level1SupportHandler = createHandler((request, next) => {
  if (request.type === "basic") {
    console.log("Level 1 Support: Handling basic inquiry.");
  } else {
    console.log("Level 1 Support: Passing to the next handler.");
    next(request);
  }
});

const level2SupportHandler = createHandler((request, next) => {
  if (request.type === "technical") {
    console.log("Level 2 Support: Handling technical issue.");
  } else {
    console.log("Level 2 Support: Passing to the next handler.");
    next(request);
  }
});

const managerHandler = createHandler((request, next) => {
  if (request.type === "escalation") {
    console.log("Manager: Handling customer escalation.");
  } else {
    console.log("Manager: No further handlers to pass.");
    next(request);
  }
});

level1SupportHandler.setNext(level2SupportHandler).setNext(managerHandler);

const basicRequest = { type: "basic" };
const technicalRequest = { type: "technical" };
const escalationRequest = { type: "escalation" };
const unknownRequest = { type: "unknown" };

level1SupportHandler.handleRequest(unknownRequest);
