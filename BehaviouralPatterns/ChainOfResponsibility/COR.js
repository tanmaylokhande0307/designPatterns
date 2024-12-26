class BaseProcessor {
  constructor() {
    this.nextHandler = null;
  }

  setNext(handler) {
    this.nextHandler = handler;
    return this.nextHandler;
  }

  process(request) {
    if (this.nextHandler) {
      return this.nextHandler.process(request);
    }
    console.log("No handler available for this request.");
  }
}

class LevelOneProcessor extends BaseProcessor {
  process(request) {
    if (request.type === "basic") {
      console.log("Level 1 Support: Handling basic inquiry.");
      return
    } else {
      console.log("Level 1 Support: Passing to the next handler.");
      return super.process(request)
    }
  }
}

class LevelTwoProcessor extends BaseProcessor {
  process(request) {
    if (request.type === "technical") {
      console.log("Level 2 Support: Handling technical issue.");
      return
    } else {
      console.log("Level 2 Support: Passing to the next handler.");
      return super.process(request)
    }
  }
}

class Manager extends BaseProcessor {
  process(request) {
    if (request.type === "escalation") {
      console.log("Manager: Handling customer escalation.");
      return
    } else {
      console.log("Manager: No further handlers to pass.");
      return super.process(request)
    }
  }
}

const level1 = new LevelOneProcessor();
const level2 = new LevelTwoProcessor();
const manager = new Manager();

level1.setNext(level2).setNext(manager);

const basicRequest = { type: "basic" };
const technicalRequest = { type: "technical" };
const escalationRequest = { type: "escalation" };
const unknownRequest = { type: "unknown" };
 

level1.process(unknownRequest);
