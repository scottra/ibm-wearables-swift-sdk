/*
*   © Copyright 2015 IBM Corp.
*
*   Licensed under the Mobile Edge iOS Framework License (the "License");
*   you may not use this file except in compliance with the License. You may find
*   a copy of the license in the license.txt file in this package.
*
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
*/

import UIKit
import IBMMobileEdge
import AVFoundation

class SensingViewController: UIViewController, UITableViewDataSource, UITableViewDelegate{
    
    
    @IBOutlet weak var detectionView: UIView!
    @IBOutlet weak var sensingView: UIView!
    
    @IBOutlet weak var detectedScore: UILabel!
    @IBOutlet weak var detectedGesture: UILabel!
    
    @IBOutlet weak var table: UITableView!
    
    @IBOutlet weak var tableView: UIStackView!
    let controller = AppDelegate.controller
    let classification = Classification()
    let jsEngine = JSEngine.instance

    var timer:NSTimer!
    
    var tableData = [ResultData]()
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        //register the listeneres to update the UI
        classification.registerListener(onGestureDetected)
        classification.registerStatusListener(onGestureStatusUpdated)
        
        //load all the JS files (it is safe to load the same JS file more than once)
        classification.loadGesturesByFilePath(FileUtils.getAllFilePaths())
        
        
    }

    override func viewDidAppear(animated: Bool){
        super.viewDidAppear(animated)
        
        clearDetectedData()
        
        //update the sensativity of the calssifier 
        updateSensitivity()
        
        //controller.registerInterpretation(classification, withListener: onGestureDetected)
        controller.registerInterpretation(classification)
        
        controller.sensors.accelerometer.on()
        controller.sensors.gyroscope.on()
    }
    
    override func viewDidDisappear(animated: Bool){
        super.viewDidDisappear(animated)
        
        //turn off the sensors before exit the screen
        controller.sensors.accelerometer.off()
        controller.sensors.gyroscope.off()
        
        controller.unregisterInterpretation(classification)
    }
    
    
    //update the classification class with the saved values of the sensitivity
    func updateSensitivity(){
        
        var payload = Dictionary<String,Double>()
        
        for name in FileUtils.getJsFileNames(){
            payload[name] = SensitivityUtils.get(name)
        }
        
        classification.setSensitivity(payload)
    }
    
    
    //parse the score results
    func onGestureStatusUpdated(additonalInfo: AnyObject!) {
        
        dispatch_async(dispatch_get_main_queue()) {
            
            self.tableData.removeAll()
            
            let scoresData = additonalInfo as! Dictionary<String, AnyObject>
            
            for element in scoresData["others"] as! Array<AnyObject> {
                
                let object = element as! Dictionary<String,String>
                
                let name = object["name"]!
                let score = Double(object["score"]!)!
                let sensitivity = Double(object["sensitivity"]!)!
                
                self.tableData.append(ResultData(name: name, withScore: score, withSensativity: sensitivity))
            }
            
            self.table.reloadData()
        }
    }
    
    func onGestureDetected(additonalInfo: AnyObject!) {
        
        dispatch_async(dispatch_get_main_queue()) {
            
            if let _ = self.timer{
                self.timer.invalidate()
            }
            
            let gestureName = additonalInfo["recognized"] as? String
            let score = additonalInfo["score"] as? Int
            let otherInfo = additonalInfo["others"] as? String
            
            self.detectionView.hidden = false
            self.sensingView.hidden = true
            self.updateGestureData(gestureName!, score: score!, otherInfo: otherInfo!)
            self.sayGestureName(gestureName!)
            
            //will clean the detected data after some delay
            self.timer = NSTimer.scheduledTimerWithTimeInterval(3, target: self, selector: "clearDetectedData", userInfo: nil, repeats: false)
        }
    }
    
    func sayGestureName(gestureName:String){
        let utterance = AVSpeechUtterance(string: gestureName)
        utterance.voice = AVSpeechSynthesisVoice(language: "en-GB")
        utterance.rate = 0.5
        
        let synthesizer = AVSpeechSynthesizer()
        synthesizer.speakUtterance(utterance)
    }
    
    func updateGestureData(gestureName:String, score:Int, otherInfo:String){
        detectedGesture.text = gestureName
        detectedScore.text = "Likelihood: \(score)%"
    }
    
    func clearDetectedData(){
        sensingView.hidden = false
        detectionView.hidden = true
    }
    
    @IBAction func onDoneClicked(sender: AnyObject) {
        self.navigationController!.popViewControllerAnimated(true)
    }
    
    @IBAction func onHideAdvancedMode(sender: AnyObject) {
        tableView.hidden = true
    }
    
    @IBAction func onShowAdvancedMode(sender: AnyObject) {
        tableView.hidden = false
    }
    
    //Table
    func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        return 1
    }
    
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return tableData.count
    }
    
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
        let cellIdentifier = "ResultCell"
        let cell = tableView.dequeueReusableCellWithIdentifier(cellIdentifier, forIndexPath: indexPath) as! ResultCell
        
        let data = tableData[indexPath.row]
        
        cell.setData(data)
        
        return cell
    }
}
