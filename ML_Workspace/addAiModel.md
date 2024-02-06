

# Loading AI Models onto STM32 CubeIDE/MX
  

This file will show the steps needed to generate the necessary models for loading a model onto STM32H745-DISCO and the steps for loading and generating the C code into an STM32 project.  

# Adding X-CUBE-AI  
  

Open project .ioc file in STM32CubeIDE or CubeMX .ioc file and go to **Middleware and Software Packs**  
  

![](https://i.ibb.co/Sc48M7w/msware.png)![photo](https://i.ibb.co/Sc48M7w/msware.png)  
  

Scroll down and find X-CUBE-AI and select it. Install AI and Device Application  
Afterwards, enable the core and select **Application Template** under Device Application, press OK.  
  

![](https://i.ibb.co/yqGmt4R/install.png)![photo](https://i.ibb.co/yqGmt4R/install.png)  
  
  

## Generating Model Files  
  

You will need to add your dataset to PhononsPhotons-TinkerSpace/ML_Workspace/Datasets (too large to keep on repo).   
  

In *PhononsPhotons-TinkerSpace/ML_Workspace* there is a script **generate_stm32.py**. You will have to replace the build_model() function if you are adding a new AI model.   
  

See Header of script for general information on running script. Example:  
![](https://i.ibb.co/GFpNqgt/rscript.png)
  
Model and Validation files will be output to *ML_Workspace/Output/Models* and *ML_Workspace/Output/Validation*.  
  

## Adding Model to STM32CubeIDE/MX  
  

Return to the X-CUBE-AI under middlewares and software packs and select **Add new Model**    
  

Fill out the information as below, add your model and validation inputs (validation outputs currently not working).   
  

Select Analyze to get data and graphs about model structure, mem allocation, etc.   
Select Validate on desktop to get accuracy, f1, recall, etc.   
  

![](https://i.ibb.co/YhPYcH9/loadmodel.png)
  
  
  

## Generate Code  
  

You can now generate code, try not to blow everything up!  


## Updating Paths

Linker Libraries add:

 *${workspace_loc:/${ProjName}/X-CUBE-AI/App}*

Includes Paths add:
 *${workspace_loc:/${ProjName}/X-CUBE-AI/App}*
 */PhonPhot_Complete_System/Middlewares/ST/AI/Inc*

Under Include Paths go to "Source Location" and add:
  */PhonPhot_Complete_CM4/X-CUBE-AI/App*